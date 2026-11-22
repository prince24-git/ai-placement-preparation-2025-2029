#include <stdio.h>

int main(void) {
    long long number;
    int odd_sum = 0;
    int even_sum = 0;

    printf("Enter a number: ");
    if (scanf("%lld", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < 0) {
        number = -number;
    }

    while (number > 0) {
        int digit = (int)(number % 10);

        if (digit % 2 == 0) {
            even_sum += digit;
        } else {
            odd_sum += digit;
        }

        number /= 10;
    }

    printf("Sum of odd digits: %d\n", odd_sum);
    printf("Sum of even digits: %d\n", even_sum);

    return 0;
}
