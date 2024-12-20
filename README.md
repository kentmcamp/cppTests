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
- `cmake ..` (generates the necessary build files base on the `CMakeList.txt` configuration).
- `cmake --build .` (Compiles the project using the build files from the previous stem).

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

- `Model`: a representation of something in reality.
- `Encapsulation`: Bundling data and the operations that manipulate it within a model, ensuring only relevant details are exposed.
- `Classes`: The primary construct in OOP for defining models
    - `Traits`: Attributes or properties of the class (data).
    - `Behaviors`: Actions or functions the class can perform (methods).
- `Object`: A specific instance of a class.
- `Class Members`: Components of a class, defined by access level:
    - `Public`: Accessible from anywhere in the program.
    - `Private`: Accessible only within the class.
    - `Protected`: Accessible from within the class and any subclasses that inherit from it.
- `Inheritance`: A mechanism where a subclass inherits members (traits and behaviors) from its parent (superclass).
- `Polymorphism`: The ability of a subclass to modify or override inherited behaviors for its specific needs.

## Creating Simple C++ Programs

- `helloWorld.cpp`

    ```cpp
    #include <iostream>

    int main() {
        std::cout << " Hello World! " << std::endl;
        std::cout << std::endl << std::endl;
        return(0);
    }
    ```

- `name.cpp`

    ```cpp
    #include <iostream>
    #include <string>

    int main() {
        std::cout << " What is your name!? " << std::endl;
        std::string userName;
        std::cin >> userName;
        std::cout << "Hello " << userName << "!";
        return(0);
    }
    ```


# Data Types

## Basic Data Types

### Integers

- Whole numbers (e.g., `0`, `21`, `243`).
- Can be **signed** (positive/negative) or **unsigned** (only positive).
- Common types:
    - `int`: Typically 32 bits, but may be 16 bits on some systems.
    - `char`: 8 bits, representing a single character or small integer.
- For portable types, use `<cstdint>` (e.g., `uint32_t` for a 32-bit unsigned integer).

### Floating-Points

- Numbers with decimals (e.g., `3.4`, `0.24`).
- Follow the IEEE 754 binary floating-point standard.
- Types:
    - `float`: Basic precision.
    - `double`: Higher precision and range, but more computationally expensive.
    - `long double`: Even greater precision and range.

### Boolean

- Keyword: `bool`.
- Values: `true` or `false` (both lowercase).
- Numerical equivalents:
    - `0` is `false`.
    - Any non-zero value is `true`.

### Strings

- Not natively supported, but there are classes that support them.
- C++ provides the `<string>` library for more powerful string manipulation.
- The `std::string` class includes many helpful functions for handling text.

### Pointers

- Special data type for memory addresses.
- Acts as references to variables or memory locations.
- Can traverse memory sequentially to access multiple variables.

## Variables

- Used to temporarily store data in memory.
- Must be declared before use, specifying:
    - **`Type`** (e.g., `int`, `float`).
    - **`Name`** - (identifier).
    - **`Initialization`** - (`int x = 5`).
- You can declared more than one variable of the same type:
    - `int a, b, c = 123`

### Constant Literals

- Fixed values directly written in the code, categorized by type:
    - **`int`**: `123`, `5`, `023` (octal), `0x21` (hex), `0b1100` (binary), `23U` (unsigned).
    - **`float`**: `23.0f`, `0.04f` (indicated by trailing `f`).
    - **`double`**: `25.3`, `22.5` (default for decimal numbers without a suffix).
    - **`char`**: `'a'`, `'X'`, `'\0'` (null character), `'\n'` (newline).
    - **`string`**: `"hello"` (requires double quotes in C++).

## Using Variables

### Global Variables

- Declared outside of the functions.
- Accessible throughout the entire program.

### Local Variables

- Declared inside a specific function or block (e.g., loops, conditional statements)
- Only accessible within the scope where they are defined.

## Expressions, Assignments, and Operations

### Expressions

- Represent a calculation, similar to algebra.
- May include variables, constants, and operators.
- Always produces a value.

### Assignments

- Assign values to variables.
- Consist of a **left-hand side** (variable) and a **right-hand side** (expression).
- The left-hand side must be able to store the value, and both sides must have compatible data types.

### Popular Operations

- **Arithmetic**: `+`, `-`, `*`, `/`, `%`
- **Bitwise**: `&`, `|`, `~`, `^`
- **Logical**: `&&`, `||`, `!`
- **Relational**: `==`, `!=`, `>`, `<`, `>=`, `<=`
- **Pointer**: `*`, `&`, `->`

## Type Inference with `auto`

- The `auto` keyword allows the compiler to deduce a variable’s type based on its initialization.

    ```cpp
    #include <iostream>
    #include <typeinfo>

    int main() {
        auto a = 8;              // int
        auto b = 12345678901;    // long long
        auto c = 3.14f;          // float
        auto d = 3.14;           // double
        auto e = true;           // bool
        auto f = 'd';            // char

        std::cout << typeid(a).name() << " integer " << a << std::endl;
        std::cout << typeid(b).name() << " int64 " << b << std::endl;
        std::cout << typeid(c).name() << " float " << c << std::endl;
        std::cout << typeid(d).name() << " double " << d << std::endl;
        std::cout << typeid(e).name() << " boolean " << e << std::endl;
        std::cout << typeid(f).name() << " character " << f << std::endl;

        return 0;
    }
    ```


## Preprocessor Directives

- Special instructions (e.g., `#include`) processed before the main compilation step.
- Used for including libraries, defining constants, and conditional compilation.
- **Syntax:** Directives start with `#` and do not end with a semicolon.
- `#include` - Includes standard or custom header files.

    ```cpp
    #include <iostream>
    #include <string>
    #include <cstdint>
    ```

- `#define` - Defines macros for simple text replacements.

    ```cpp
    #define CAPACITY 5000
    int main() {
        int large = CAPACITY;  // Replaced with 5000
        std::cout << "large = " << large << std::endl;
        return 0;
    }
    ```

- `#ifdef` and `#endif` - Conditional compilation based on macro definitions.

    ```cpp
    #define DEBUG

    int main() {
        int a = 5, b = 6;

    #ifdef DEBUG
        std::cout << "A = " << a << ", B = " << b << std::endl;
    #endif

        return 0;
    }
    ```


## Constants

- Identifiers with values that will not change during execution.
- Useful as parameters in your code.
- May be implemented with directives (`#define`) or as variables.

### Constants as Directives

- The `#define` directive schedules a find-and-replace operation.

### The `const` Qualifier

- Used in a regular variable declaration.
- Declarations specify a type.
- Scope encapsulation is enforced.
- `const` is not the same in C and C++.

## Arrays

- Collections of data
- All data is homogeneous; of the same data type.
- Fixed size.
- Contiguous in memory.

## Strings

- Strings in C++ are arrays of characters or objects of the `std::string` class.

    ```cpp
    #include <iostream>
    #include <string>
    #include <cstring>

    int main() {
        const int LENGTH1 = 25;
        char array_str1[LENGTH1] = "Hey there!";
        char array_str2[] = "What's up?";
    		// to make a string variable you could:
    		std::string array_str3;

        std::string std_str1 = "Hi everybody!";
        std::string std_str2 = "How's it going?";

        std::strcat(array_str1, array_str2); // First argument is the destination, second argument is the source. strcat is a function from the cstring library.
        std::cout << array_str1 << std::endl;

        std::cout << std_str1 + std_str2 << std::endl; // With strings, the + operator is overloaded to concatenate strings.

        return 0;
    ```


## Type Casting

- Converts one data type to another.
- Syntax: `(type)(expression)` for explicit casting.

### Examples:

- Truncating `float` to `int`:

    ```cpp
    float flt = -7.44f;
    int sgn = (int)flt;  // Explicit cast
    std::cout << "sgn = " << sgn << std::endl;  // Outputs -7
    ```

- Preventing integer division in calculations:

    ```cpp
    int fahrenheit = 100;
    float celsius = ((float)5 / 9) * (fahrenheit - 32);
    std::cout << "Celsius = " << celsius << std::endl;
    ```

- Extracting fractional part of a `float`:

    ```cpp
    float weight = 10.99;
    std::cout << "Fractional: " << (int)((weight - (int)weight) * 10000) << std::endl;
    ```


# Structures, Classes, and Pointers

## Structures

## Enumerations

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

---

- `codeblocks`
    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```

    - `

        ```cpp

        ```
