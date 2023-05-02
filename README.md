# Equation Solver
This is a C++ program that takes in a mathematical equation as a string and returns the result.

## Dependencies
- iostream
- string
- cmath
## Installation
1. Clone or download the repository.
2. Compile the main.cpp file.
3. Run the executable.
## Usage
1. Run the executable.
2. Enter a mathematical equation when prompted. For example, 2 + 2 or 4 / (2 + 2).
3. Press Enter to submit the equation.
4. The program will print the result of the equation to the console.
5. To exit the program, type q and press Enter.

## How it Works
The program takes the user input equation as a string and parses it character by character using a for loop. It then extracts the left-hand and right-hand sides of the equation and determines the type of mathematical operation to perform based on the operator (+, -, *, /) present in the equation. The program uses the switch statement to determine which operation to perform and then calculates the result. If the equation is invalid, the program catches the exception and prints an error message to the console.

The program uses the Equation class to encapsulate the equation parsing and result calculation logic. The main function takes user input and creates an Equation object to handle the input.

## Known ShortFalls

- Doesn't handle negative numbers
- Only handles basic arithmatic operations ('+', '-', '*', '/')
