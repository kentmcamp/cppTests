#include <iostream>

int main() {
    int numberLength = 5;
    float numbers[5];
    float total = 0;
    float average = 0;

    for (int i = 0; i < numberLength; i++) {
        std::cout << "Enter number " << i+1 << ": ";
        std::cin >> numbers[i];
        total += numbers[i];
    }

    average = total / numberLength;

    std::cout << "The total sum: " << total << std::endl;;
    std::cout << "The average is: " << average << std::endl;

    return 0;
}
