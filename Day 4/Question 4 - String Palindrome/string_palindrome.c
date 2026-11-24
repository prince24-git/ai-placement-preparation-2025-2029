#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000000

static int is_palindrome(const char *text) {
    size_t left = 0;
    size_t right = strlen(text); /* exclusive right boundary */

    while (left < right) {
        while (left < right && !isalnum((unsigned char)text[left])) {
            ++left;
        }
        while (left < right && !isalnum((unsigned char)text[right - 1])) {
            --right;
        }
        if (left < right) {
            int left_char = tolower((unsigned char)text[left]);
            int right_char = tolower((unsigned char)text[right - 1]);
            if (left_char != right_char) {
                return 0;
            }
            ++left;
            --right;
        }
    }
    return 1;
}

int main(void) {
    char text[MAX_LENGTH];
    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }
    text[strcspn(text, "\r\n")] = '\0';

    clock_t start_time = clock();
    int result = is_palindrome(text);
    clock_t end_time = clock();
    double elapsed_seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("%s\n", result ? "Palindrome" : "Not a palindrome");
    printf("Elapsed CPU time: %.9f seconds\n", elapsed_seconds);
    return 0;
}
