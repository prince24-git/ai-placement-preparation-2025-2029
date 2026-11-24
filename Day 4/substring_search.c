#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void build_lps(const char *pattern, size_t length, size_t *lps) {
    size_t prefix_length = 0;
    lps[0] = 0;

    for (size_t i = 1; i < length;) {
        if (pattern[i] == pattern[prefix_length]) {
            lps[i++] = ++prefix_length;
        } else if (prefix_length != 0) {
            prefix_length = lps[prefix_length - 1];
        } else {
            lps[i++] = 0;
        }
    }
}

static int contains_substring(const char *text, const char *pattern) {
    size_t n = strlen(text);
    size_t m = strlen(pattern);
    if (m == 0) return 1;
    if (m > n) return 0;

    size_t *lps = (size_t *)malloc(m * sizeof(size_t));
    if (lps == NULL) return -1;
    build_lps(pattern, m, lps);

    size_t i = 0; /* index in text */
    size_t j = 0; /* index in pattern */
    int found = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
            if (j == m) {
                found = 1;
                break;
            }
        } else if (j != 0) {
            j = lps[j - 1];
        } else {
            ++i;
        }
    }

    free(lps);
    return found;
}

int main(void) {
    char text[1000000];
    char pattern[1000000];

    printf("Enter the main string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    text[strcspn(text, "\r\n")] = '\0';

    printf("Enter the substring to find: ");
    if (fgets(pattern, sizeof(pattern), stdin) == NULL) return 1;
    pattern[strcspn(pattern, "\r\n")] = '\0';

    int result = contains_substring(text, pattern);
    if (result < 0) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("%s\n", result ? "Substring found" : "Substring not found");
    return 0;
}
