# Submodules Documentation

## MLX Submodule

Ce projet utilise MLX (MiniLibX) comme submodule Git.

### Commandes utiles :

#### Cloner le projet avec ses submodules :
```bash
git clone --recursive <your-repo-url>
```

#### Ou si vous avez déjà cloné sans les submodules :
```bash
git submodule update --init --recursive
```

#### Mettre à jour les submodules :
```bash
make submodules
# ou directement :
git submodule update --remote
```

#### Vérifier l'état des submodules :
```bash
git submodule status
```

### Structure :
- `mlx/` → Submodule pointant vers https://github.com/42Paris/minilibx-linux.git
- Le Makefile gère automatiquement l'initialisation du submodule si nécessaire

### Notes :
- Le submodule MLX est automatiquement vérifié et initialisé lors de la compilation
- Utilisez `make submodules` pour mettre à jour manuellement
