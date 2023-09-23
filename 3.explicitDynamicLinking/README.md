# Calculator Library

This C++ library, `libcalculator`, provides a set of mathematical and bitwise operations. It allows you to perform basic arithmetic calculations, as well as some advanced mathematical operations and bitwise operations. This README provides an overview of the library, how to compile it into a shared library, and how to use it in a main program.

## Introduction

The `libcalculator` library is a collection of mathematical and bitwise functions that can be used in C++ programs. It is designed to be simple to use and provides a wide range of functionality, from basic arithmetic operations to advanced mathematical calculations and bitwise manipulations.

## Compilation

To compile the `libcalculator` library into a shared library and the main program, follow these steps:

### Step 1: Compile the Shared Library

```bash
# On Linux
g++ -shared -o calculator.so lib* -fPIC
```

### Step 2: Compile the Main Program  

```bash
# On Linux
g++ -o main Main.cpp validation.cpp Calculator.cpp  -ldl
```  

## Explicit dynamic linking functions  
In your code, you are using explicit dynamic linking to load functions from a shared library (`calculator.so`) at runtime. This allows you to dynamically load and use functions from the library without the need for a static linkage at compile time. Here's an explanation of the key functions and concepts in your code:

1. `dlfcn.h`: This header file provides the necessary functions and data types for dynamic linking. It is part of the POSIX standard and is used to load shared libraries and access their symbols at runtime.

2. `dlopen()`: This function is used to open a shared library at runtime and returns a handle to the library. It takes the name of the shared library file as an argument and flags indicating how the library should be loaded. In your code, `RTLD_LAZY` is used, which means that symbols will be resolved as needed.

3. `dlsym()`: This function is used to retrieve a pointer to a function or a data object from a shared library. It takes the library handle returned by `dlopen()` and the name of the symbol you want to retrieve. In your code, you use it to get pointers to various functions defined in the shared library.

4. `dlerror()`: This function retrieves a human-readable string describing the most recent error that occurred with dynamic linking. It is used to handle potential errors during dynamic linking. You check the result of `dlsym()` for errors using `dlerror()`.

5. Function Pointers: You declare function pointers for each of the functions you want to use from the shared library. For example, you declare `addition` as a function pointer for the `addition()` function defined in the library. You cast the result of `dlsym()` to the appropriate function pointer type.

6. `logicalOperation` and `AthematicOperation` Arrays: These arrays store function pointers for the logical and arithmetic operations you want to perform. You initialize these arrays with the appropriate function pointers based on the operations you support.

7. `switch (Operator)`: This switch statement is used to determine which operation to perform based on the `Operator` character passed as an argument to the `calculator` function. Depending on the operator, it calls the corresponding function pointer from either `logicalOperation` or `AthematicOperation` arrays.

8. `dlclose()`: This function is used to close the shared library handle when you are done using it. It should be called after you have finished using the functions from the library.



