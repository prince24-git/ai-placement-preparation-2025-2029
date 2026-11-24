#include <iostream>
#include <string>
#include <vector>

std::vector<std::size_t> build_lps(const std::string &pattern) {
    std::vector<std::size_t> lps(pattern.size(), 0);
    std::size_t prefix_length = 0;

    for (std::size_t i = 1; i < pattern.size();) {
        if (pattern[i] == pattern[prefix_length]) {
            lps[i++] = ++prefix_length;
        } else if (prefix_length != 0) {
            prefix_length = lps[prefix_length - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

bool contains_substring(const std::string &text, const std::string &pattern) {
    if (pattern.empty()) return true;
    if (pattern.size() > text.size()) return false;

    const std::vector<std::size_t> lps = build_lps(pattern);
    std::size_t i = 0; // index in text
    std::size_t j = 0; // index in pattern

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
            if (j == pattern.size()) return true;
        } else if (j != 0) {
            j = lps[j - 1];
        } else {
            ++i;
        }
    }
    return false;
}

int main() {
    std::string text;
    std::string pattern;

    std::cout << "Enter the main string: ";
    std::getline(std::cin, text);
    std::cout << "Enter the substring to find: ";
    std::getline(std::cin, pattern);

    std::cout << (contains_substring(text, pattern)
                      ? "Substring found\n"
                      : "Substring not found\n");
    return 0;
}
