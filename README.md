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
- `arrayLoop.cpp`

    ```cpp
    #include <iostream>
    #include <string>

    int main() {
        int age [4];
        age[4] = 3;

        for (int i = 0; i < (sizeof(age)/sizeof(age[0])) - 1; i++) {
            age[i] = i;
            std::cout << age[i] << std::endl;
        }
        std::cout << age[4];
        return(0);
    }
    ```


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


## Enumerations

### Enumerators (Enums) inherited from C

- `Enumerators` (or `enums`) are user-defined data types that consists of a set of named integral constants.
- `Enums` are used to assign names to integral constants, making the code more readable and maintainable.
    - `enum Color { RED, GREEN, BLUE };`
- By  default, the first enum has the value `0`, the second `1`, and so on (not unlike arrays). You can assign specific values however.
    - `enum Color { RED = 3, GREEN = 2, BLUE = 1 };`

### Enum Classes (Scoped Enums) in C++

- `Enum Classes` (or `scoped enums`) are a type-safe and scoped version of traditional enums introduced in C++11.
- `Enum Classes` provide a better type safety and avoid name clashes by scoping the enumerators within the enum class.
    - `enum class Color { RED, GREEN, BLUE };`
- Enumerators are accessed using the scope resolution operator: `::`
    - `Color myColor = Color::RED;`
- You can also specify the underlying type of the enum class:
    - `enum class Color : int { RED = 1, GREEN = 2, BLUE = 3};`

# Structures, Classes, and Pointers

## Structures

- Containers of heterogeneous data members.
- Useful for implementing simple models
    - `movie-struct.cpp`

        ```cpp
        #include <iostream>
        #include <string>

        struct movie{
            std::string title;
            std::string director;
            int year;
            float rating;
            bool watched;
        };

        int main() {

            movie madmax;
            madmax.title = "Mad Max: Fury Road";
            madmax.director = "George Miller";
            madmax.year = 2015;
            madmax.rating = 4.5;
            madmax.watched = 1;

            std::cout << "The movie is " << madmax.title << ", directed by " << madmax.director << " in " << madmax.year << ". It's rating is " << madmax.rating << "." << std::endl;

            std::cout << "Did I watch it? ";
            if (madmax.watched) {
                std::cout << "Yes";
            } else {
                std::cout << "No";
            }

            return(0);
        }
        ```


## Classes

- Basic elements of OOP
- Contain `data` and `function` members.

### Properties

- Properties can be private, public, or protected. But it’s a good idea to only make functions public.
    - **Example:**

        ```cpp
        class movie {
        private:
            std::string title;
            std::string director;
            int year;
            float rating;
        public:
            bool watched;
        };
        ```


### Getters / Accessors

- `Getters` is how you retrieve private member values without external modification.
- Since you don’t want to change anything via a `Getter`, it’s a good idea to add the `const` keyword:
    - **Example:**

        ```cpp
        // Getters
        std::string get_name() const{
            return title;
        };
        std::string get_director() const{
            return director;
        };
        int get_year() const{
            return year;
        };
        float get_rating() const{
            return rating;
        };
        bool get_watched() const{
            return watched;
        };
        ```


### Setters / Modifiers

- Updates private member values safely.
    - **Example:**

        ```cpp
        // Setters
        void set_name(std::string title_i){
            title = title_i;
        };
        void set_director(std::string director_i){
            director = director_i;
        };
        void set_year(int year_i){
            year = year_i;
        };
        void set_rating(float rating_i){
            rating = rating_i;
        };
        void set_watched(bool watched_i){
            watched = watched_i;
        };
        ```


### Constructors

- Initialize class objects when created. They match the class name, and have no return type.

    ### Default Constructors

    - No arguments; initializes members to default values.

        ```cpp
        class Person {
        private:
            std::string name;
            int age;

        public:
            Person() : name(""), age(0) {}
        };
        ```


    ### Overloading Constructors

    - Allows multiple constructors with different parameters.

        ```cpp
        class Person {
        private:
            std::string name;
            int age;

        public:
            Person() : name(""), age(0) {}
            Person(std::string newName) : name(newName), age(0) {}
            Person(std::string newName, int newAge) : name(newName), age(newAge) {}
        };

        ```

- `movie-class.cpp`

    ```cpp
    #include <iostream>
    #include <string>

    class movie {
    public:

        // Constructors
        // Default constructor
        movie() {
            title = "No title";
            director = "No director";
            year = 0;
            rating = 0.0;
            watched = false;
        }

        // Parameterized constructor
        movie(std::string title_i, std::string director_, int year_i, float rating_i, bool watched_i) {
            title = title_i;
            director = director_;
            year = year_i;
            rating = rating_i;
            watched = watched_i;
        }

        // Getters
        std::string get_name() const{
            return title;
        };
        std::string get_director() const{
            return director;
        };
        int get_year() const{
            return year;
        };
        float get_rating() const{
            return rating;
        };
        bool get_watched() const{
            return watched;
        };

        // Setters
        void set_name(std::string title_i){
            title = title_i;
        };
        void set_director(std::string director_i){
            director = director_i;
        };
        void set_year(int year_i){
            year = year_i;
        };
        void set_rating(float rating_i){
            rating = rating_i;
        };
        void set_watched(bool watched_i){
            watched = watched_i;
        };

    private:
        std::string title;
        std::string director;
        int year;
        float rating;
        bool watched;
    };

    int main() {

        movie madmax("Mad Max: Fury Road", "George Miller", 2015, 4.5, true);

        std::cout << "The movie is " << madmax.get_name() << ", directed by " << madmax.get_director() << " in " << madmax.get_year() << ". It's rating is " << madmax.get_rating() << "." << std::endl;

        std::cout << "Did I watch it? ";
        if (madmax.get_watched() == true)
        {
            std::cout << "Yes" << std::endl;;
        }
        else
        {
            std::cout << "No" << std::endl;;
        }

        madmax.set_rating(5.0);
        std::cout << "Actually, I changed my rating to a " << madmax.get_rating() << std::endl;

        return (0);
    }
    ```


## Header and Implementation Files

- `Header Files (.h)`: Contain class definitions and function declarations.
- `Implementation Files (.cpp)`: Contain executable code, must include their corresponding headers.

## Using Several Source Files

## Pointers

- Variables storing memory addresses.
- Use `&` to get an address, and `*` to dereference it.
    - **Example:**

        ```cpp
        int a = 37;
        int* ptr = &a;

        std::cout << "Value of a: " << a << std::endl;
        std::cout << "Address of a: " << &a << std::endl;
        std::cout << "Value of ptr: " << ptr << std::endl;
        std::cout << "Dereferenced ptr: " << *ptr << std::endl;
        ```


## References

- Another name for an existing variable.
- Use `&` in declarations, no reassignment.
    - **Example:**

        ```cpp
        int a = 10;
        int& ref = a;

        std::cout << "Value of a: " << a << std::endl;
        std::cout << "Value of ref: " << ref << std::endl;

        ref = 20;
        std::cout << "Updated value of a: " << a << std::endl;
        ```


## Vectors

- Dynamic arrays from the Standard Template Library (STL)
- Include `<vector>` to use.
    - **Example:**

        ```cpp
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> numbers = {1, 2, 3, 4, 5};

            for (int num : numbers) {
                std::cout << num << " ";
            }
            return 0;
        }
        ```


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
