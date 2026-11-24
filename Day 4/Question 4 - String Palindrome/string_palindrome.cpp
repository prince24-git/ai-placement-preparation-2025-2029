#include <cctype>
#include <ctime>
#include <iostream>
#include <string>

bool is_palindrome(const std::string &text) {
    std::size_t left = 0;
    std::size_t right = text.size(); /* exclusive right boundary */

    while (left < right) {
        while (left < right &&
               !std::isalnum(static_cast<unsigned char>(text[left]))) {
            ++left;
        }
        while (left < right &&
               !std::isalnum(static_cast<unsigned char>(text[right - 1]))) {
            --right;
        }
        if (left < right) {
            char left_char = static_cast<char>(
                std::tolower(static_cast<unsigned char>(text[left])));
            char right_char = static_cast<char>(
                std::tolower(static_cast<unsigned char>(text[right - 1])));
            if (left_char != right_char) {
                return false;
            }
            ++left;
            --right;
        }
    }
    return true;
}

int main() {
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    std::clock_t start_time = std::clock();
    bool result = is_palindrome(text);
    std::clock_t end_time = std::clock();
    double elapsed_seconds =
        static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << (result ? "Palindrome\n" : "Not a palindrome\n");
    std::cout << "Elapsed CPU time: " << elapsed_seconds << " seconds\n";
    return 0;
}
