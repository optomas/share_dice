# share_dice

A lightweight, command-line utility written in C for simulating dice rolls. It supports standard dice notation (e.g., 3d6) and utilizes a fast PRNG with rejection sampling to ensure perfectly fair results.

## Features
- **Dice Notation:** Input format like `3d6` (3 dice with 6 sides).
- **Fairness:** Employs Xorshift64 for fast pseudo-random number generation.
- **Modulo Bias Protection:** Uses rejection sampling to ensure every possible outcome has an equal probability.
- **Standard C:** Written in clean, standard C11 with no external dependencies.

## Project Structure
/home/theo/code/C/share_dice/

├── bin/            # Compiled binaries

├── doc/            # Project documentation

├── include/        # Header files (.h)

├── src/            # Source files (.c)

├── Makefile        # Build configuration

└── README.md       # Project overview


## Build and Run

### Prerequisites
Make sure you have a standard C compiler (like `gcc`) and `make` installed.

### Building the Project
To compile the application, run the following command in the root directory:

make

This will compile the source files and place the executable inside the `bin/` directory.

### Running the Utility
Execute the compiled binary from the root directory, passing your desired dice roll as an argument:

./bin/dice_roll 3d6

### Cleaning Up
To remove compiled object files and binaries, run:
make clean
