# Cub3D

## Summary
Cub3D is a group project that was inspired by the world-renowned 90's game and the first-ever First Person Shooter, Wolfenstein 3D. This project allowed us to explore the technique of ray-casting, where the objective was to create a dynamic view within a maze, and the ultimate goal was to find a way out.

## Project Structure

The repository is organized with the following structure:

- Makefile: Automation script for compilation and project management.
- inc/: folder containing header files function prototypes and necessary definitions.
- src/subdir/*.c: Source files implementing various functions.

## Rules

- The project must be written in C.
- Adherence to the `42 School` Norm is mandatory.
- The program should not terminate unexpectedly, and memory must be handled properly to avoid leaks.
- Allowed External Functions: open, close, read, write, malloc, free, perror, strerror, exit

## Usage

```bash
make
./cub3D [map].cub
```

Maps are provided in the `maps/` folder.

## Features

- `w` `s` `a` `d` : Move forward / backward / left / right
- `←` `→` : Rotate the view
- `ESC` : Exit

## Rendering

- Render using an isometric projection based on `Bresenham algorithm`.
- Input coordinates provided in a file, with each number representing a point's position and altitude.
- Utilize [Minilibx](https://github.com/42Paris/minilibx-linux) library for rendering. The MinilibX is a simple X-Window (X11R6) programming API in C, designed for students, suitable for X-beginners.
- Display the rendering in a window.
- Ensure smooth window management (resizing, minimizing, etc.).

## Acquired Skills

- Understanding and implementing graphic rendering techniques.
- Working with external libraries like MiniLibX.
- Effectively managing memory and avoiding memory leaks.
- Developing a robust and well-structured C program.
- Handling user interactions in a graphical environment.

# Troubleshooting

If the git submodules didn't clone properly, you can run the following commands to clone the submodules:

```bash
git submodule update --init --force --remote
```

For macOS users, the project needs a X11 server to run. You can install it with [`Homebrew`](https://brew.sh/) using the following command:

```bash
brew install xquartz libx11 libext
reboot
```

If you have an issue with the window size, you can change the corresponding macros in the include file `cub3d_macros.h` located in the `inc/` folder:

```c
# define WIDTH 1200
# define HEIGHT 1500
```
