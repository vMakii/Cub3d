# 🎯 Guide LERP (Linear Interpolation)

## Qu'est-ce que LERP ?

**LERP** (Linear Interpolation) est utilisé dans énormément de domaines au-delà du brouillard. C'est la formule de mélange linéaire pour créer des transitions fluides entre deux valeurs.

### Formule de base :
```c
result = A * (1.0f - t) + B * t;
// Où t va de 0.0 à 1.0
// t=0.0 → 100% de A, 0% de B
// t=1.0 → 0% de A, 100% de B
```

## 🎮 **Jeux Vidéo / Graphiques :**

### **1. Animation de mouvement :**
```c
// Déplacement fluide d'un objet de A vers B
pos.x = start_x * (1.0f - t) + end_x * t;
pos.y = start_y * (1.0f - t) + end_y * t;
// t va de 0.0 à 1.0 au fil du temps
```

### **2. Transition de couleurs :**
```c
// Changement progressif de couleur (rouge vers bleu)
r = 255 * (1.0f - t) + 0 * t;     // Rouge diminue
g = 0;                            // Vert constant
b = 0 * (1.0f - t) + 255 * t;     // Bleu augmente
```

### **3. Camera smoothing :**
```c
// Caméra qui suit le joueur en douceur
camera.x = camera.x * 0.9f + player.x * 0.1f;  // 90% ancien + 10% nouveau
```

### **4. Fade in/out :**
```c
// Fondu de transparence
alpha = 0 * (1.0f - fade_progress) + 255 * fade_progress;
```

## 🎵 **Audio :**

### **5. Volume crossfade :**
```c
// Transition entre deux musiques
final_volume = music1_vol * (1.0f - t) + music2_vol * t;
```

### **6. Pitch bending :**
```c
// Changement progressif de hauteur sonore
pitch = low_pitch * (1.0f - t) + high_pitch * t;
```

## 🤖 **Intelligence Artificielle :**

### **7. Pathfinding smooth :**
```c
// Lissage de trajectoire IA
smooth_path.x = waypoint1.x * (1.0f - t) + waypoint2.x * t;
```

### **8. Comportement émergent :**
```c
// Mélange entre "agressif" et "passif"
aggression = passive_behavior * (1.0f - mood) + aggressive_behavior * mood;
```

## 📱 **Interface Utilisateur :**

### **9. Animations de boutons :**
```c
// Bouton qui grandit au survol
scale = 1.0f * (1.0f - hover_t) + 1.2f * hover_t;
```

### **10. Scroll smooth :**
```c
// Défilement fluide de page
scroll_pos = old_pos * 0.8f + target_pos * 0.2f;
```

## 🧮 **Mathématiques / Physique :**

### **11. Interpolation de données :**
```c
// Valeurs entre deux points de mesure
temperature = temp_9h * (1.0f - ratio) + temp_10h * ratio;
```

### **12. Simulation physique :**
```c
// Amortissement de ressort
velocity = velocity * damping + target_velocity * (1.0f - damping);
```

## 🎨 **Effets Visuels :**

### **13. Particules :**
```c
// Vie des particules (taille, couleur, transparence)
particle_size = max_size * (1.0f - life_ratio) + 0 * life_ratio;
```

### **14. Lighting :**
```c
// Transition jour/nuit
final_light = day_light * sun_factor + night_light * (1.0f - sun_factor);
```

## 🌫️ **Exemple dans notre projet cub3D :**

### **Effet de brouillard :**
```c
static unsigned int fog_effect(unsigned int color, float factor)
{
    if (factor >= 1.0f) return color;
    if (factor <= 0.0f) return (120 << 16) | (120 << 8) | 120;
    
    unsigned char r = (color >> 16) & 0xFF;
    unsigned char g = (color >> 8) & 0xFF;
    unsigned char b = color & 0xFF;
    
    // LERP entre couleur originale et gris brouillard
    r = (unsigned char)(r * factor + 120 * (1.0f - factor));
    g = (unsigned char)(g * factor + 120 * (1.0f - factor));
    b = (unsigned char)(b * factor + 120 * (1.0f - factor));
    
    return (r << 16) | (g << 8) | b;
}
```

### **Décomposition mathématique :**

| Factor | Effet | Calcul pour rouge (255) |
|--------|-------|-------------------------|
| **1.0f** | Aucun brouillard | `255 * 1.0 + 120 * 0.0 = 255` |
| **0.8f** | Léger brouillard | `255 * 0.8 + 120 * 0.2 = 228` |
| **0.5f** | Brouillard moyen | `255 * 0.5 + 120 * 0.5 = 187` |
| **0.2f** | Fort brouillard | `255 * 0.2 + 120 * 0.8 = 147` |
| **0.0f** | Brouillard total | `255 * 0.0 + 120 * 1.0 = 120` |

## 💡 **Pourquoi LERP est si populaire :**

1. **⚡ Rapide** : Seulement une multiplication et une addition
2. **🎯 Prévisible** : Résultat toujours entre A et B
3. **🔄 Réversible** : Facile d'inverser la transition
4. **📐 Linéaire** : Progression uniforme et naturelle
5. **🛠️ Versatile** : Fonctionne avec n'importe quel type numérique

## 🔧 **Variantes de LERP :**

### **SLERP (Spherical Linear Interpolation) :**
- Pour les rotations en 3D
- Interpolation sur une sphère

### **Smoothstep :**
```c
// Transition plus douce aux extrémités
float smoothstep(float t) {
    return t * t * (3.0f - 2.0f * t);
}
```

### **Ease-in/Ease-out :**
```c
// Accélération/décélération
float ease_in_out(float t) {
    return t < 0.5f ? 2.0f * t * t : 1.0f - 2.0f * (1.0f - t) * (1.0f - t);
}
```

---

**LERP est l'outil de base pour créer des transitions fluides dans pratiquement tous les domaines numériques !** 🚀

C'est pourquoi vous le retrouvez partout : du brouillard de votre raycaster aux animations d'interface, en passant par l'IA et la physique !
