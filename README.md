# Number Guessing Game

Welcome to the Number Guessing Game! This game challenges you to guess a randomly generated number within a specified range and a limited number of attempts. It includes multiple difficulty levels and provides hints to help you get closer to the correct number.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Modes](#game-modes)
- [How to Play](#how-to-play)
- [Medals](#medals)
- [License](#license)

## Introduction

The Number Guessing Game is a simple console-based game written in C++. Players can choose from three difficulty levels: Easy, Medium, and Hard. Each level comes with its own range of numbers and a limited number of attempts to guess the correct number.

## Features

- Multiple difficulty levels (Easy, Medium, Hard)
- Hints provided based on the player's guess
- Scoring system with medals (Gold, Silver, Bronze)
- Option to play again after each game

## Installation

To run the game, follow these steps:

1. Make sure you have a C++ compiler installed (e.g., g++ for GCC).
2. Download or clone the repository to your local machine.
3. Compile the `main.cpp` file using your C++ compiler.

```sh
g++ main.cpp -o NumberGuessingGame
```

4. Run the compiled executable.
```sh
./NumberGuessingGame
```
Usage
Upon running the game, you will be presented with a menu to start the game or exit. Once you start the game, you can choose a difficulty level. The game will then prompt you to guess the number within the specified range and provide hints based on your guesses.

Game Modes
Easy: Guess a number between 1 and 50 with 10 attempts.
Medium: Guess a number between 1 and 100 with 7 attempts.
Hard: Guess a number between 1 and 200 with 5 attempts.
How to Play
Start the game by selecting option 1 from the main menu.
Choose your preferred difficulty level.
Guess the number within the range provided for your selected mode.
Use the hints provided to get closer to the correct number.
If you guess the number within the allowed attempts, you win and receive a medal based on your performance.
Choose whether to play again or exit the game.
Medals
The game awards medals based on the number of attempts taken to guess the correct number:

Gold Medal: Awarded for guessing the number in fewer than 3 attempts.
Silver Medal: Awarded for guessing the number in 3 to 4 attempts.
Bronze Medal: Awarded for guessing the number in 5 to 6 attempts.
Each medal is represented with a unique ASCII art design.

License
This project is open source and available under the MIT License.


You can customize this `README.md` file further as per your requirements. Save it as `README.md` in the root directory of your project repository.
