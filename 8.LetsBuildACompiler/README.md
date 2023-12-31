# Simple Programming Language Compiler

This is a simple C++ program that demonstrates the implementation of a lexer, parser, and basic semantic analyzer for a simple programming language. The code is designed to tokenize, parse, and perform basic semantic checks on source code written in the custom language.

## Features

- **Lexer**: Tokenizes the input source code into smaller units called tokens. Tokens represent the basic building blocks of the language, including identifiers, integers, operators, and keywords.

- **Parser**: Parses the stream of tokens generated by the lexer and constructs an Abstract Syntax Tree (AST) representing the structure of the program. The parser defines rules for various language constructs like variable declarations, assignments, expressions, functions, if statements, and while loops.

- **Semantic Analyzer**: Performs basic semantic analysis, including:
    - Checking for undeclared variables and redefined variables.
    - Type checking for variable assignments.
    - Enforcing correct function call arguments.
    - Verifying the existence of functions before they are called.

- **Error Handling**: The code uses exceptions to report errors, such as syntax errors or semantic errors. Error messages include information about the line number where the error occurred.

## Usage

1. Clone the repository or download the source code to your local machine.

2. Compile the code using a C++ compiler:

   ```bash
   g++ main.cpp -o compiler  
   ``` 
3. Run the compiled binary:

    ```bash
    ./compiler
    ```