# Snake-Game-Cpp
A classic Snake game built in C++17 using SFML 3 and CMake, featuring real-time movement, collision detection, scoring, increasing difficulty, pause/resume, and restart functionality.
# 🐍 Snake Game — C++ & SFML

A classic Snake game built from scratch using **C++17**, **SFML 3**, and **CMake**.

The project demonstrates object-oriented programming, real-time game loops, event handling, collision detection, STL containers, and basic game-state management.

## 🎮 Features

* ⌨️ Arrow keys and WASD controls
* 🍎 Random food generation
* 🐍 Dynamic snake growth
* 💥 Wall collision detection
* 💀 Self-collision detection
* 🏆 Score and high-score tracking
* ⚡ Increasing difficulty as the score increases
* ⏸️ Pause / resume
* 🔄 Restart after game over
* 🧩 Object-oriented architecture
* ⚙️ CMake-based build system

## 🛠️ Tech Stack

* **Language:** C++17
* **Graphics:** SFML 3
* **Build System:** CMake
* **Standard Library:** STL
* **Compiler:** MSVC / GCC / Clang

## 📁 Project Structure

```text
SnakeGame-CPP-SFML/
│
├── CMakeLists.txt
├── README.md
├── requirements.txt
│
├── include/
│   ├── Game.h
│   └── Snake.h
│
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   └── Snake.cpp
│
└── assets/
    └── fonts/
```

## 🧠 Architecture

The project separates the game into two main classes.

### `Snake`

Responsible for:

* Snake body management
* Movement
* Direction changes
* Growth
* Self-collision
* Snake rendering

### `Game`

Responsible for:

* Main game loop
* Keyboard input
* Food generation
* Score management
* Difficulty
* Collision detection
* Game state
* Rendering

## 🔄 Game Loop

The game continuously performs four main operations:

```text
┌─────────────────┐
│ Process Events  │
└────────┬────────┘
         ↓
┌─────────────────┐
│ Update Game     │
│ State           │
└────────┬────────┘
         ↓
┌─────────────────┐
│ Collision Check │
└────────┬────────┘
         ↓
┌─────────────────┐
│ Render Frame    │
└────────┬────────┘
         │
         └──────────────→ Repeat
```

## 💥 Collision Detection

### Wall Collision

The game checks whether the snake's head has moved outside the playable grid.

```cpp
head.x < 0
head.x >= GRID_WIDTH
head.y < 0
head.y >= GRID_HEIGHT
```

If any condition is true, the game ends.

### Self Collision

The snake's head is compared with each segment of its body.

```text
Head → Body Segment 1
     → Body Segment 2
     → Body Segment 3
     → ...
```

If the head overlaps with the body, the game ends.

### Food Collision

When the snake's head reaches the food:

```text
Snake grows
     ↓
Score increases
     ↓
New food appears
     ↓
Game becomes slightly faster
```

## ⚡ Difficulty System

The initial movement delay is approximately:

```text
0.15 seconds
```

The snake becomes faster as the score increases.

A minimum delay prevents the game from becoming unrealistically fast:

```text
Minimum delay = 0.05 seconds
```

## 🎮 Controls

| Key   | Action                  |
| ----- | ----------------------- |
| ↑ / W | Move Up                 |
| ↓ / S | Move Down               |
| ← / A | Move Left               |
| → / D | Move Right              |
| P     | Pause / Resume          |
| Enter | Restart after Game Over |
| Esc   | Exit                    |

## 💻 Installation

### Prerequisites

Install:

* C++17-compatible compiler
* CMake 3.20+
* SFML 3
* Git
* vcpkg (recommended on Windows)

### Install SFML with vcpkg

Clone vcpkg:

```powershell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

Install SFML:

```powershell
.\vcpkg install sfml:x64-windows
```

## 🔨 Build

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/SnakeGame-CPP-SFML.git
cd SnakeGame-CPP-SFML
```

Configure CMake:

```powershell
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
```

Build:

```powershell
cmake --build build --config Release
```

Run:

```powershell
.\build\Release\SnakeGame.exe
```

> If vcpkg is installed in a different location, update the toolchain path accordingly.

## 📚 What I Learned

This project helped reinforce several C++ and software-engineering concepts:

* Object-oriented programming
* Classes and encapsulation
* Header/source separation
* STL `std::vector`
* References and `const`
* Event-driven programming
* Real-time game loops
* Collision detection
* State management
* CMake
* SFML graphics and events

## 🚀 Future Improvements

Planned improvements include:

* [ ] In-game score display
* [ ] Graphical game-over screen
* [ ] Start menu
* [ ] Difficulty selection
* [ ] Sound effects
* [ ] Background music
* [ ] Persistent high score
* [ ] Obstacles
* [ ] Power-ups
* [ ] Multiple maps
* [ ] Better animations
* [ ] Unit tests
* [ ] GitHub Actions CI/CD

## 📸 Screenshots

Add screenshots here after running the game:

```markdown
![Gameplay](assets/gameplay.png)
```

## 📄 License

This project is intended for learning and portfolio use.
