# cub3D

_This project has been created as part of the 42 curriculum by mivogel and gburtin._

`cub3D` is a raycasting engine written in C, inspired by Wolfenstein 3D. The engine renders a real-time first-person 3D view of a 2D map using the DDA (Digital Differential Analyzer) algorithm, and a playable game is built on top of it.

## Description

### Goal

Build a 3D game engine from scratch in C using only the **MiniLibX** graphics library. The engine reads a `.cub` scene file describing the map layout, textures, and colors, then renders a first-person view of the environment at 60 degrees FOV in a 1333×1000 window.

### Key Features

**Mandatory**
- DDA raycasting with perpendicular distance correction (no fisheye distortion).
- Per-column texture mapping on walls (100×100 px textures, sub-pixel accuracy).
- `.cub` map file parser with strict validation: wall closure via flood-fill, player spawn check, RGB color format, texture path declarations.
- Player movement with WASD + arrow keys and collision detection (0.1 unit margin).
- Configurable flat floor and ceiling colors.

**Bonus**
- Textured floor and ceiling rendering (128×128 px tiles).
- Double-wall rendering for a layered wall effect.
- Z-buffer for correct sprite depth ordering.
- Three animated enemy types (Skeleton, Werewolf, Zombie) with distinct stats, AI, and multi-frame animations.
- Animated doors with open/close toggle and per-frame smooth transition.
- HUD: health bar, minimap (16×18 tile radius), enemy markers.
- Three weapons (Fist, Sword, Magic Sword) with distinct damage and range.
- Animated player arms and weapon sprites.
- Floor/ceiling/lamp/treasure sprites rendered in world space.
- Hit effect animations (blood splashes on screen edges).
- Start menu with navigation and death screen.
- Delta-time scaled movement and frametime-aware animation system.
- Custom garbage collector for memory cleanup.

## Team

| Login     | 42 Login  |
| --------- | --------- |
| `mivogel` | mivogel   |
| `gburtin` | gburtin   |

## Technical Stack

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)<br/>
![MiniLibX](https://img.shields.io/badge/MiniLibX-42Paris-555555?style=for-the-badge&labelColor=00BABC)<br/>
![Make](https://img.shields.io/badge/Makefile-build_system-555555?style=for-the-badge&logo=gnu&logoColor=white&labelColor=A42E2B)<br/>

- **MiniLibX** (42Paris) — X11 window and image management, loaded as a git submodule.
- **libft** — 42 standard C library.
- **DDA algorithm** — per-column ray marching with perpendicular wall distance for fisheye correction.

## Project Structure

```
mandatory/
├── Makefile
├── SUBMODULES.md
├── includes/              # Header files and structs
├── libft/                 # 42 standard library
├── mlx/                   # MiniLibX submodule (42Paris)
├── assets/
│   └── png/               # Textures: walls, ceiling, floor, doors, enemies, sprites
├── maps/                  # .cub scene files
├── srcs/                  # Mandatory sources
│   ├── main.c
│   ├── parsing/           # .cub file reader and flood-fill validator
│   ├── raycasting/        # DDA loop, texture coordinate mapping
│   ├── render/            # Frame composition
│   ├── img/               # Image helpers
│   ├── init/              # Engine initialization
│   ├── mov/               # Player movement and collision
│   └── utils/
└── srcs_bonus/            # Bonus sources
    ├── main_bonus.c
    ├── parsing/           # Extended parser (doors, sprites, enemy spawns)
    ├── raycasting/        # Enhanced DDA with Z-buffer and door awareness
    ├── enemies/           # Skeleton, Werewolf, Zombie — AI, animation, combat
    ├── doors/             # Door state machine and animation
    ├── hud/               # Health bar, minimap, enemy markers
    ├── effects/           # Blood splash hit effects
    ├── sprites/           # Floor/ceiling/lamp/treasure sprites
    ├── screens/           # Start menu and death screen
    ├── inputs/            # Keyboard and mouse handlers
    ├── move/              # Movement with delta-time and enemy collision
    ├── player/            # Player stats, weapons, arm/hand animation
    └── utils/
```

## Map Format

Maps use the `.cub` format. A valid scene file must declare four wall textures, floor and ceiling colors, and a valid closed map grid.

```
NO ./assets/png/north.png
SO ./assets/png/south.png
WE ./assets/png/west.png
EA ./assets/png/east.png

F 220,100,0
C 225,30,0

        1111111111111111
        1000000000110001
        1011000001110001
        100N000000000001
        1111111111111111
```

**Mandatory characters:**

| Character | Meaning                             |
| --------- | ----------------------------------- |
| `0`       | Walkable floor                      |
| `1`       | Wall                                |
| `N/S/E/W` | Player spawn position and direction |
| ` `       | Out-of-bounds padding               |

**Bonus-only characters:**

| Character | Meaning               |
| --------- | --------------------- |
| `D`       | Door                  |
| `M`       | Enemy spawn point     |
| `T`       | Treasure sprite       |
| `L`       | Lamp sprite (animated)|
| `C`       | Random ceiling sprite |
| `F`       | Random floor sprite   |

## Enemies

Three enemy types are randomly assigned to `M` spawn points:

| Type       | HP  | Speed        | Attack range | Damage | Attack cooldown |
| ---------- | --- | ------------ | ------------ | ------ | --------------- |
| Werewolf   | 100 | 0.03 u/frame | 0.9 units    | 5 HP   | 10 frames       |
| Skeleton   | 80  | 0.02 u/frame | 0.7 units    | 8 HP   | 30 frames       |
| Zombie     | 150 | 0.01 u/frame | 0.8 units    | 12 HP  | 20 frames       |

Enemies detect the player via line-of-sight within an aggro radius of 80 units, then chase and attack. They are blocked by closed doors and knocked back on hit.

## Weapons

The player starts with the Fist. Press `Left Ctrl` to cycle through weapons:

| Weapon      | Damage | Range    |
| ----------- | ------ | -------- |
| Fist        | 10 HP  | 0.7 units|
| Sword       | 25 HP  | 1.0 unit |
| Magic Sword | 40 HP  | 1.2 units|

## Controls

| Key / Input           | Action                                 |
| --------------------- | -------------------------------------- |
| `W A S D`             | Move forward / left / backward / right |
| `←` `→`               | Rotate camera left / right             |
| Mouse movement        | Rotate camera (horizontal look)        |
| `Space` / `Left click`| Attack                                 |
| `Left Shift`          | Run                                    |
| `E`                   | Cast / heal (toggle)                   |
| `Left Ctrl`           | Change weapon                          |
| `F`                   | Interact with door                     |
| `ESC`                 | Quit                                   |

## Instructions

### Prerequisites

- Linux with X11
- GCC and `make`
- X11 development libraries

```bash
sudo apt install gcc make libx11-dev libxext-dev
```

### Clone with submodules

MiniLibX is a git submodule:

```bash
git clone --recursive <your-repo-url>
```

If already cloned without submodules:

```bash
git submodule update --init --recursive
```

### Build

```bash
# Mandatory + bonus
make

# Bonus only
make bonus

make clean    # Remove object files
make fclean   # Remove binaries
make re       # Full rebuild
```

### Run

```bash
# Mandatory
./mandatory/cub3D mandatory/maps/default.cub

# Bonus
./mandatory/cub3D_bonus mandatory/maps/sprites.cub
```

## Resources

- [MiniLibX (42Paris)](https://github.com/42Paris/minilibx-linux)
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [DDA Algorithm — Wikipedia](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))

### AI Usage

AI was used as an assistant for documentation drafting and debugging. All suggestions were reviewed and tested before use.
