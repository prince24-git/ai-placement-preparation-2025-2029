#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 256

int main(void) {
    int n;
    char strings[MAX_STRINGS][MAX_LENGTH];
    char temporary[MAX_LENGTH];

    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_STRINGS) {
        fprintf(stderr, "Enter a count from 1 to %d.\n", MAX_STRINGS);
        return 1;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }

    printf("Enter each string on a new line:\n");
    for (int i = 0; i < n; i++) {
        if (fgets(strings[i], MAX_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Could not read string %d.\n", i + 1);
            return 1;
        }
        strings[i][strcspn(strings[i], "\r\n")] = '\0';
    }

    for (int end = n - 1; end > 0; end--) {
        int swapped = 0;
        for (int i = 0; i < end; i++) {
            if (strcmp(strings[i], strings[i + 1]) > 0) {
                strcpy(temporary, strings[i]);
                strcpy(strings[i], strings[i + 1]);
                strcpy(strings[i + 1], temporary);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    printf("Strings in lexicographical order:\n");
    for (int i = 0; i < n; i++) puts(strings[i]);
    return 0;
}
