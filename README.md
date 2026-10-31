# Phantom Bounce

Phantom Bounce is a fast, arcade-style pong-like reaction game built with C++ and raylib. The player guides a paddle across the bottom of the screen, trying to keep colored balls from hitting a wall of the opposite color while scoring points and surviving increasingly chaotic phantom effects like ghost balls and camouflage.

## What the game is about

The game mixes classic bouncing-ball mechanics with a twist:

- The blue ball and red ball are the main active objects.
- The paddle is a wide green bar that the player moves left and right.
- Each time a ball hits the paddle, it bounces back,on hitting a wall of the same color the score increases.
- If a blue or red ball reaches the opposite color edge, the game ends and the score resets.
- There are also ghost balls that appear later in the game and become more active as the score rises.
- Phantom balls are semi-transparent at first, can swap positions with active balls, and become more visible as the game progresses(So they are harder to distinguish from the real balls).
- There are special progression moments (for example, after reaching certain score thresholds) that trigger new mechanics like camouflage, mute collisions, and a final win state.
- The game tracks both the current score and the high score.

The core goal is to survive as long as possible and reach the victory condition at a score of 500.

## Controls

- Enter: Start the game / continue after game over
- Left Arrow: Move paddle left
- Right Arrow: Move paddle right
- P: Pause the game
- R: Resume after pausing
- H: Open the help screen
- M: Return to the main menu
- Esc / window close: Exit the game

## How to run

### Prerequisites

You will need:

- A C++ compiler (MinGW, MSVC, or similar)
- The raylib C++ library installed and available to the compiler
- The assets in the same folder as the executable, or run the program from the repository root so the game can find them

### Required files

The game loads audio and image files directly from the current working directory, including:

- game.cpp
- gamebgv1.png
- bounce.wav
- GameOver.wav
- Lazerhawk.mp3
- Stereo Madness.mp3
- purple_motions.xm

### Compile

From the repository root, compile the project with raylib linked in:

```bash
g++ game.cpp -o PhantomBounce.exe -O2 -lraylib -lopengl32 -lgdi32 -lwinmm
```

If your raylib installation is not in the default compiler path, you may need to use the include and library paths explicitly, for example:

```bash
g++ game.cpp -o PhantomBounce.exe -O2 -I/path/to/raylib/include -L/path/to/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Run

Launch the executable from the project directory so the game can locate the asset files:

```bash
./PhantomBounce.exe
```

or on Windows:

```powershell
PhantomBounce.exe
```

## Gameplay notes

- The title screen shows the game name and offers a help screen.
- The help screen explains the rules, including ghost-ball behavior and teleportation effects.
- The game uses raylib audio streams for music and sound effects.
- As the score increases, the difficulty changes and more phantom effects appear.
- Reaching a score of 500 triggers a win screen.

## Notes

This project is a single-file raylib game and is designed to be run directly from the project folder with all media assets present. If the executable is moved away from the asset folder, sound and textures may fail to load.

