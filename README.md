# pingPongGame
 Using C++
# Ping Pong Game - README

## Overview

This project is a simple Ping Pong game implemented in C++ using the Raylib library. The game simulates a classic table tennis match where players control paddles to hit a ball back and forth. The game features both single-player and two-player modes.

## Prerequisites

- **Operating System**: Windows, macOS, or Linux
- **Compiler**: GCC, Clang, or MSVC
- **Libraries**: Raylib

## Files in the Project

- `main.cpp`: Main source code file containing the game logic.
- `Player.h` and `Player.cpp`: Class definition and implementation for the player paddles.
- `Ball.h` and `Ball.cpp`: Class definition and implementation for the ball.
- `Makefile`: Makefile for compiling the project (optional, for Unix-like systems).

## Setup and Compilation

1. **Install Raylib**:
   Follow the instructions on the [Raylib official website](https://www.raylib.com/) to install Raylib on your system.

2. **Directory Structure**:
   Organize your project directory as follows:
   ```
   PingPong/
   ├── main.cpp
   ├── Player.h
   ├── Player.cpp
   ├── Ball.h
   ├── Ball.cpp
   ├── Makefile (optional)
   ```

3. **Compile the Project**:

   - **Using Makefile (Unix-like systems)**:
     Open a terminal, navigate to the project directory, and run:
     ```sh
     make
     ```
   
   - **Manual Compilation (All systems)**:
     Open a terminal or command prompt, navigate to the project directory, and run:
     ```sh
     g++ -o pingpong main.cpp Player.cpp Ball.cpp -lraylib
     ```
     Ensure you have the Raylib library installed and properly linked.

## Running the Game

To run the game, execute the compiled `pingpong` binary:
```sh
./pingpong
```

## Source Code Overview

### main.cpp

This file contains the main game loop, initialization of Raylib, and the main gameplay logic. Key sections include:

- **Initialization**: Setting up the game window and initializing game objects.
- **Game Loop**: The main loop that handles input, updates game state, and renders the graphics.
- **Cleanup**: Closing the game window and freeing resources.

### Player.h and Player.cpp

These files define and implement the `Player` class, representing the paddles controlled by the players. Key methods include:

- **Constructor**: Initializes the paddle's position and size.
- **Update**: Handles the movement of the paddle based on player input or AI logic.
- **Draw**: Renders the paddle on the screen.

### Ball.h and Ball.cpp

These files define and implement the `Ball` class, representing the ball in the game. Key methods include:

- **Constructor**: Initializes the ball's position, velocity, and size.
- **Update**: Updates the ball's position and handles collisions with the paddles and screen edges.
- **Draw**: Renders the ball on the screen.

## Key Functions

- **InitializeGame**: Sets up initial game state and objects.
- **UpdateGame**: Updates game logic, including player input and ball movement.
- **DrawGame**: Renders the game objects and updates the display.
- **UnloadGame**: Frees resources and closes the game window.

## Game Modes

- **Single-Player Mode**: Player controls the left paddle, and the right paddle is controlled by a simple AI.
- **Two-Player Mode**: Two players control both paddles.

## Controls

- **Player 1**: Use `W` and `S` keys to move the paddle up and down.
- **Player 2**: Use `Up Arrow` and `Down Arrow` keys to move the paddle up and down.

## Support

For any issues or questions, please contact the project maintainer at `raoumair554@.com`.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

**Disclaimer**: This software is provided "as-is" without any warranties. Use at your own risk. The author is not responsible for any misuse of this software.

---

By using this software, you agree to adhere to all applicable laws and regulations regarding the use of software libraries and game development frameworks.

---

This README provides a high-level overview of the Ping Pong game project. For more detailed information, please refer to the comments within the source code files.
