# Documentation des Portes - Cub3D

## ✅ Système Complet de Portes Implémenté

### Fonctionnalités

#### 1. Définition des portes sur la carte
- Les portes sont définies par le caractère `D` sur la carte
- Elles peuvent être placées n'importe où dans la carte comme les murs (`1`)
- Validation automatique lors du parsing

#### 2. Gestion des portes
- **État initial** : Toutes les portes commencent fermées
- **Collision** : Les portes fermées bloquent le mouvement du joueur
- **Interaction** : Le joueur peut ouvrir/fermer les portes avec la touche `E`
- **Distance d'interaction** : 1.5 unités devant le joueur
- **Feedback** : Message console lors de l'interaction

#### 3. Animation des portes
- **Vitesse d'ouverture** : 0.05 par frame (configurable)
- **Effet de double porte** : La porte s'ouvre par le milieu comme une vraie double porte
- **Ouverture progressive** : Le centre de la texture devient transparent en premier
- **Compression des côtés** : Les parties gauche et droite de la texture se compriment vers les bords
- **Transparence réaliste** : Raycasting complet à travers les portes ouvertes
- **Rendu authentique** : Affichage des vraies textures de murs, sol et plafond derrière les portes
- **Effet de profondeur** : Calcul correct des hauteurs de murs, zones de plafond et de sol
- **Perspective correcte** : Les murs derrière les portes respectent leur vraie distance et hauteur
- **Seuil de passage** : Les portes laissent passer le joueur quand elles sont ouvertes à 70% ou plus

#### 4. Rendu visuel
- Les portes utilisent une texture dédiée (index 4 dans le système de textures)
- Elles bénéficient des mêmes effets de distance et d'éclairage que les murs
- Animation fluide avec effet d'ouverture par le milieu (double porte)
- Compression réaliste de la texture vers les bords lors de l'ouverture
- Raycasting complet à travers les portes ouvertes pour afficher l'environnement réel
- Rendu authentique des murs, sol et plafond derrière les portes selon leur vraie distance

## Configuration

### Fichiers modifiés
1. `includes/cub3d.h` - Ajout des structures et déclarations
2. `srcs/doors/doors.c` - Système de gestion des portes (nouveau fichier)
3. `srcs/raycasting/my_raycast.c` - Integration du rendu des portes
4. `srcs/mov/keypress.c` - Ajout de l'interaction avec la touche 'E'
5. `srcs/parsing/check_map.c` - Validation des portes dans la carte
6. `srcs/utils/utils.c` - Ajout de 'D' aux caractères valides
7. `srcs/make/srcs.mk` - Ajout du fichier doors.c au Makefile

### Structures ajoutées
```c
typedef struct s_door
{
    t_coord_int    pos;         // Position de la porte
    bool           is_open;     // État ouvert/fermé
    float          open_amount; // Degré d'ouverture (0.0-1.0)
    float          open_speed;  // Vitesse d'animation
} t_door;

typedef struct s_door_list
{
    t_door *doors;
    int    count;
    int    capacity;
} t_door_list;
```

## Utilisation

### Contrôles
- `E` : Ouvrir/Fermer une porte (quand le joueur est face à une porte)
- Les autres contrôles restent inchangés

### Exemple de carte avec portes
```
11111111111
10000000001
10000D00001
10000000001
10N00000001
10000D00001
10000000001
11111111111
```

### Fonctions principales
- `init_doors(t_data *data)` - Initialise le système de portes
- `load_doors_from_map(t_data *data)` - Charge les portes depuis la carte
- `update_doors(t_data *data)` - Met à jour les animations
- `toggle_door_at_position(t_data *data, int x, int y)` - Change l'état d'une porte
- `is_door_blocking(t_data *data, int x, int y)` - Vérifie si une porte bloque le passage

## Notes techniques
- Les portes sont gérées comme des objets dynamiques avec animation
- Elles utilisent le système de garbage collector existant
- Compatible avec tous les systèmes existants (minimap, sprites, etc.)
- Performance optimisée : les portes ne sont mises à jour que si nécessaire

### Algorithme d'ouverture par le milieu (Version finale)
L'effet de double porte est réalisé par :
1. **Calcul du centre** : La texture est divisée en deux moitiés (gauche/droite)
2. **Zone d'ouverture** : Les pixels proches du centre deviennent transparents progressivement
3. **Compression des côtés** : Les parties restantes sont compressées vers les bords extérieurs
4. **Ratio d'ouverture** : `door_open_amount` contrôle la largeur de la zone transparente
5. **Mapping des coordonnées** : Les coordonnées de texture sont recalculées pour créer l'effet de compression

### Système de transparence par raycasting complet
- **Raycasting continu** : Les rayons traversent les portes ouvertes et continuent dans l'environnement
- **Rendu authentique** : Affichage des vraies textures de murs, sol et plafond selon leur distance réelle
- **Textures correctes** : Utilisation des vraies textures de sol et plafond avec projection perspective correcte
- **Projection perspective** : Sol et plafond utilisent la même projection que le rendu normal (`pos_z / p`)
- **Calcul de perspective murs** : Les murs derrière les portes ont la bonne hauteur selon leur distance
- **Zones correctes** : Distinction automatique entre plafond (avec texture), murs (avec texture) et sol (avec texture)
- **Coordination texture** : Calcul des coordonnées de texture basé sur la position mondiale réelle avec perspective
- **Effets de distance complets** : Application d'assombrissement selon la distance pour tous les éléments (murs, sol, plafond)
- **Cohérence visuelle** : Même paramètres d'assombrissement que le rendu normal (`distance_factor = 1.0f - (distance / 12.0f)`)
- **Performance optimisée** : Raycasting efficace sans impact significatif sur les FPS

### Contrôles et utilisation
- **E** : Ouvrir/Fermer une porte (face à une porte à distance d'interaction)
- **WASD** : Déplacement standard
- **Flèches** : Rotation de la caméra
- **Espace** : Attaque
- **Ctrl** : Changement d'arme

L'effet final simule parfaitement l'ouverture de portes à deux battants avec un vrai raycasting à travers les ouvertures, permettant de voir l'environnement réel derrière les portes (murs avec textures et distance, sol avec textures perspective-correctes et distance, plafond avec textures perspective-correctes et distance) basé sur les coordonnées mondiales exactes, la même projection que le rendu normal, et les mêmes effets de distance, avec des performances optimales.
