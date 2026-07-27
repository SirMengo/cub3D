
*This project has been created as part of the 42 curriculum by msimoes, xalves*

## Description
Cub3D is a first-person maze renderer built using the MinilibX graphics library, inspired by the raycasting behind old classic 3D games like Wolfenstein 3D. The player explores a map/maze rendered in real time from a `.cub` scene file, with textured walls and colored floor/ceiling, and can freely move and look around.

The goal of this project is to learn the fundamentals of raycasting, 2D-to-3D projection, texture mapping, and scene file parsing, while handling memory properly and validating that every map is well-formed before it's rendered.

## Instructions

### Compilation
To compile the project simply run:
```bash
make
```
To recompile everything run:
```bash
make re
```

Both of these will create a `cub3D` executable.

### Usage
```bash
./cub3D <map.cub>
```
Texture paths inside the `.cub` file are loaded relative to the current working directory, so run the executable from the project root.

### Map Format
Maps must be `.cub` files/extensions and follow these rules:
- Four wall texture paths must be defined, one per identifier: `NO` (north), `SO` (south), `WE` (west), `EA` (east)
- Floor and ceiling colors must be defined as `F` and `C`, each in a `R,G,B` format(0-255) (ex: 139,69,19)
- Each identifier (`NO`, `SO`, `WE`, `EA`, `F`, `C`) may appear exactly once
- The map grid itself is made up of `0` (empty space), `1` (wall), and one player starting position/orientation: `N`, `S`, `E`, or `W`
- Every open tile must be fully enclosed by walls; a tile that touches the outside of the map is rejected

### Controls
| Key | Action |
|-----|--------|
| `W` | Move forward |
| `A` | Strafe left |
| `S` | Move backward |
| `D` | Strafe right |
| `←` | Turn left |
| `→` | Turn right |
| `ESC` | Exit the game |

### Examples
Basic game launch:
```bash
./cub3D ba.cub
```
```bash
./cub3D srcs/a.cub
```

### Cleanup
Remove object files:
```bash
make clean
```
Remove object files and executable:
```bash
make fclean
```

## Resources
- [MinilibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [MinilibX - Basic introduction, tutorials, tips & tricks.](https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html)
- [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [3DSage - Make Your Own Raycaster Part 1](https://youtu.be/gYRrGTC7GtA?si=aZH6GoCajpImk3Uu)
- [3DSage - Make Your Own Raycaster Part 2](https://youtu.be/PC1RaETIx3Y?si=MswRHtX5U8oVqvvR)
- [XPM format - Wikipedia](https://en.wikipedia.org/wiki/X_PixMap)

### AI usage
AI was used to help relearn the math around the raycast, especially the Sin, Cos and Tan. AI was used to create a draft of this README.
