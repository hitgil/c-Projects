# Custom atof Function in C++

This C++ program includes a custom implementation of the `atof` function, which converts a string to a floating-point number. The program also defines custom `isspace` and `isdigit` functions to handle whitespace and digit checks.

## Custom Functions ##

1. Bool isspace(char ch)  
This function checks if a character is a space (' '). It returns true if the character is a space and false otherwise.

1. bool isdigit(char ch)  
This function checks if a character is a digit (0-9). It returns true if the character is a digit and false otherwise.
1. double atof(char *ch)  
This function takes a character array (char *ch) as input and converts it to a floating-point number. It handles spaces, digits, and decimal points, returning the corresponding numeric value.
