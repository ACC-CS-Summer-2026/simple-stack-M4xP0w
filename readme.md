# Assignment 4: Simple Int Stack

## Description

This project implements a simple integer stack abstract data type using a fixed-size static array. The stack supports pushing values, popping values, peeking at the top value, and checking whether the stack is empty.

The purpose of this assignment is to practice abstract data types, class design, separate header and implementation files, error handling, and developer testing.

## Files

* `main.h` - Includes the libraries and project headers needed for testing.
* `main.cpp` - Contains the main testing code for the stack.
* `stack.h` - Declares the `Stack` class, the stack size constant, attributes, and public methods.
* `stack.cpp` - Implements the stack methods.
* `essay.md` - Contains the AI usage statement and essay.
* `README.md` - Explains the project, files, and build instructions.

## Stack Operations

The stack supports the following public operations:

* `bool push(int value)` - Adds an integer to the top of the stack if the stack is not full.
* `bool pop(int* value)` - Removes the top value from the stack and stores it through the pointer if the stack is not empty.
* `bool peek(int* value)` - Stores the top value through the pointer without removing it if the stack is not empty.
* `bool isEmpty()` - Returns whether the stack is empty.

The `pop` and `peek` methods use a boolean return value to show success or failure. This avoids using a special integer value as an error code because any integer could be a valid stack value.

## Compile

To compile the project, run:

```bash
g++ -Wall -Wextra -pedantic *.cpp -o /tmp/simple_stack_test
```

## Run

To run the program after compiling, run:

```bash
/tmp/simple_stack_test
```

## Testing

The test code is written directly in `main.cpp`.

The tests check:

* Empty stack behavior
* Push operations
* Pop operations
* Peek operations
* LIFO order
* Underflow
* Overflow
* Null pointer handling for incorrect input
* Dynamic behavior based on `STACK_SIZE`
* Random operations compared against an expected model

The program prints whether each major test section passes and gives a final result at the end.
