#include <iostream>
#include <cstdlib>

int main() {
    long long number;
    int odd_sum = 0;
    int even_sum = 0;

    std::cout << "Enter a number: ";
    if (!(std::cin >> number)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    number = std::llabs(number);

    while (number > 0) {
        int digit = static_cast<int>(number % 10);

        if (digit % 2 == 0) {
            even_sum += digit;
        } else {
            odd_sum += digit;
        }

        number /= 10;
    }

    std::cout << "Sum of odd digits: " << odd_sum << '\n';
    std::cout << "Sum of even digits: " << even_sum << '\n';

    return 0;
}
