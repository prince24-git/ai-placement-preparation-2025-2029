#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
    int n;
    std::cout << "Enter number of strings: ";
    if (!(std::cin >> n) || n < 1) {
        std::cerr << "Enter a positive count.\n";
        return 1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> strings(n);
    std::cout << "Enter each string on a new line:\n";
    for (std::string& value : strings) std::getline(std::cin, value);

    for (int end = n - 1; end > 0; --end) {
        bool swapped = false;
        for (int i = 0; i < end; ++i) {
            if (strings[i] > strings[i + 1]) {
                std::string temporary = strings[i];
                strings[i] = strings[i + 1];
                strings[i + 1] = temporary;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    std::cout << "Strings in lexicographical order:\n";
    for (const std::string& value : strings) std::cout << value << '\n';
    return 0;
}
