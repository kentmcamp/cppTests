// This program lets you see what version of C++ your compiler compiles to by default.
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
