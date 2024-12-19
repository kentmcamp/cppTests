# `Compiling C++`

### Single C++ File Compilation:

- `g++ -o filename.exe codefile.cpp`

### Multiple C++ Files Compilation:

- `g++ -o filename.exe file1.cpp file2.cpp file3.cpp`

### Including `.cpp` Files From Another Directory

- `g++ -o fileName.exe main.cpp other/classes/otherClass.cpp`

### Including `.h` Header Files From Another Directory

- `g++ -I/other/headers -o fileName.exe main.cpp other/classes/otherClass.cpp`
- `NOTE:` If your header files are in the same directory as your `main.cpp`, you don’t need to include any extra flags or references to the files.

### Using `CMake` to Manage the Build Process

- `CmakeList.txt`

    ```cpp
    cmake_minimum_required(VERSION 3.10)
    project(MyProject)

    # Set the C++ standard
    set(CMAKE_CXX_STANDARD 11)

    # Include directories
    include_directories(other/headers)

    # Add the executable
    add_executable(myprogram main.cpp other/classes/otherClass.cpp)
    ```

- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake --build .`

### Notes on Tags

- `-o` specifies the name of the output file.
    - If you don’t use this flag, the compiler will create an executable with a default name like `a.exe`
- `-I` specifies additional directories to include for header files.
- `-g` is used to include debugging information in the compiled executable.
- `-std=c++##` is used to specify what version of C++ that **GCC** compiles to.

### Checking What Version of C++ You Compile To

- When you compile using `g++` you can specify what version of `C++` it gets compiled to with the `-std` flag.
    - `g++ -std=c++17 -o program main.cpp`
        - This compiles to version 17.
- If you want to see what version of `C++` you version of `g++` compiles to by default (without using the `-std` flag) you can create, compile and run this program:
    - `check_version.exe`

        ```cpp
        #include <iostream>

        int main() {
            #if __cplusplus == 201103L
                std::cout << "C++11" << std::endl;
            #elif __cplusplus == 201402L
                std::cout << "C++14" << std::endl;
            #elif __cplusplus == 201703L
                std::cout << "C++17" << std::endl;
            #elif __cplusplus > 201703L
                std::cout << "C++20 or later" << std::endl;
            #else
                std::cout << "Pre-C++11" << std::endl;
            #endif
            return 0;
        }
        ```


# Getting Started

## Elements of OOP

-

## Creating Simple C++ Programs

# Data Types

## Basic Data Types

## Variables

## Using Variables

## Expressions, Assignments, and Operations

## Type Inference with Auto

## Preprocessor Directives

## Constants

## Arrays

## Strings

## Type Casting

## Type Casting Examples

## Enumerations

# Structures, Classes, and Pointers

## Structures

## Classes

## Using Classes

## Header and Implementation Files

## Using Several Source Files

## Pointers

## Using Objects with Pointers

## References

## Vectors

## Using Objects with Vectors

# Control Flow

## If Statements

## Switch Statements

## While Loops

## For Loops

# Functions

## Creating Functions

## Function Parameters

## Using Functions

# File I/O

## Opening a Text File for Reading

## Open a Text File for Writing
