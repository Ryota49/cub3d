# cub3d

*This project has been created as part of the 42 curriculum by *jemonthi* and *byonis*.*

## Description

**Cub3D** is a project from the 42 curriculum focused on creating a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective, using the **ray-casting** technique.

The main objective of this project is to understand the fundamentals of ray-casting, how it works, and how it can be used to transform a 2D map into a 3D-like environment.

The program takes **exactly one argument**: a `.cub` map file containing all the information required to build the game environment.

### Map Configuration

The `.cub` file must contain the following elements:

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 128,128,128
C 255,220,0
```

* `NO`: North wall texture
* `SO`: South wall texture
* `WE`: West wall texture
* `EA`: East wall texture
* `F`: Floor color in RGB format
* `C`: Ceiling color in RGB format

Each of these identifiers must appear **exactly once** in the configuration file.

Texture filenames can be different, but textures must use either the `.xpm` or `.png` extension.

The RGB values for the floor (`F`) and ceiling (`C`) can be any valid RGB values between `0` and `255`.

### Map Layout

The configuration must be followed by the map layout.

For example:

```text
                1111111111111111111111111
                100000000110000000000001
                1111000001110000000000001
                10010000000000000000000011111111
        111111111011000001110000000000001
        100000000011000001110111111111111
        11110111111111011100000010001
        11110111111111011101010010001
        11000000110101011100000010001
        10000000000000001100000010001
        10000000000000001101010000001
        11000001110101011111011110N0111
        11110111 1110101 101111010001
        11111111 1111111 111111111111
        11111111111111111111111111111
```

The following characters are allowed in the map:

* `1` — Wall
* `0` — Walkable space
* `N` — Player starting position, facing North
* `S` — Player starting position, facing South
* `E` — Player starting position, facing East
* `W` — Player starting position, facing West
* Spaces and tabs can be used within the map

The map must be **fully enclosed by walls**. The player must never be able to reach an empty space outside the playable area.

Exactly **one player starting position** must be present in the map.

Any unknown or invalid character found in the map must result in an error.

### Controls

The player can move using:

| Key   | Action              |
| ----- | ------------------- |
| `W`   | Move forward        |
| `S`   | Move backward       |
| `A`   | Move left           |
| `D`   | Move right          |
| `←`   | Rotate camera left  |
| `→`   | Rotate camera right |
| `ESC` | Exit the program    |

## Instructions

To compile the mandatory part, run `make` from the root of the repository:

```bash
make
```

This compiles the project and the required **MacroLibX** library, producing the `cub3d` executable.

You can then launch the program by providing a `.cub` map file:

```bash
./cub3d maps/map_subject2.cub
```

A window will open displaying the player's first-person view of the maze.

### Bonus

The bonus features can be compiled using:

```bash
make bonus
```

The program can then be launched in the same way:

```bash
./cub3d maps/map_subject2.cub
```

The bonus implementation includes the additional features required by the 42 Cub3D bonus specification.

### Cleaning

To remove the object files and other compilation artifacts:

```bash
make clean
```

To remove all generated files, including the executable:

```bash
make fclean
```

## Resources

* [W3Schools — C Math Reference](https://www.w3schools.com/c/c_ref_math.php)
* [MacroLibX documentation](https://macrolibx.kbz8.me/guides/getting_started/)
* [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html)

### AI Assistance

AI tools were occasionally used as a support resource when we encountered complex problems or needed help understanding specific concepts.

All code was reviewed, tested, and integrated by the project authors.
