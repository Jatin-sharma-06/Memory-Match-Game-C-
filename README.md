# 🧠 Memory Match Game

A simple console-based memory matching game created using C++! This project uses ANSI C-style logic and is built with standard C++ libraries and Windows API for cursor positioning.

## 🎮 Game Overview

- The game board is a 5x4 grid (20 cells) containing 10 pairs of hidden letters (A-J).
- The objective is to match all pairs by revealing two cells at a time.
- Each correct match reveals the pair permanently; incorrect guesses flip back.
- The game continues until all pairs are revealed.

## 🛠️ Features

- Console-based UI with grid layout
- Randomized item placement
- Simple input system using coordinates (e.g., `A0`, `C3`)
- Keeps track of number of tries
- Game logic encapsulated in a `Game` class
- ANSI C-style formatting with modern C++ syntax

## 📷 Sample Gameplay

Enter the coordinates of the first cell (e.g., A0): A1
Enter the coordinates of the second cell (e.g., A1): B2
Not a match. Try again.
...
Congratulations! You completed the game in 18 tries.

markdown
Copy
Edit

## 💻 How to Run

### Prerequisites

- **OS**: Windows (due to `windows.h` dependency for cursor positioning)
- **Compiler**: A C++ compiler (e.g., MinGW, MSVC)
- **IDE**: Recommended to use **Visual Studio** or **Code::Blocks** or **Dev C++** or **IntelliJ IDEA with C++ plugin**

### Compilation and Execution (via Command Line)

1. Save the code in a file named `main.cpp`.
2. Open Command Prompt and navigate to the project folder.
3. Compile using:

g++ main.cpp -o MemoryGame.exe

markdown
Copy
Edit

4. Run the game:

MemoryGame.exe

pgsql
Copy
Edit

> Note: `windows.h` is used for setting cursor position. This will only work on Windows terminals.

## 📁 Project Structure

📦 MemoryMatchGame
┣ 📄 main.cpp
┗ 📄 README.md

yaml
Copy
Edit

## ✍️ Credits

Made with ❤️ by [Your Name]  
Based on the **ANSI C Game Projects** logic, implemented using C++.

## 📜 License

This project is open-source and free to use for educational or personal use.

---

Feel free to star ⭐ this repo if you like the project!
