#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void)
{
    int a[SIZE];
    srand((unsigned int)time(NULL));

    printf("Initial array:\n");
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand() % 101 - 50;
        printf("%5d", a[i]);
    }
    printf("\n");

    int minimum = a[0];
    int min_index = 0;
    int first_positive = -1;
    int last_positive = -1;

    for (int i = 0; i < SIZE; ++i) {
        if (a[i] < minimum) {
            minimum = a[i];
            min_index = i;
        }

        if (a[i] > 0) {
            if (first_positive == -1) {
                first_positive = i;
            }
            last_positive = i;
        }
    }

    printf("Minimum: %d\n", minimum);
    printf("Position (from 1): %d\n", min_index + 1);
    printf("Index (from 0): %d\n", min_index);

    if (first_positive == -1 ||
        first_positive == last_positive) {
        printf("Fewer than two positive elements: no interval.\n");
    } else {
        int sum = 0;

        for (int i = first_positive + 1;
             i < last_positive; ++i) {
            sum += a[i];
        }

        printf("First positive position: %d\n",
               first_positive + 1);
        printf("Last positive position: %d\n",
               last_positive + 1);
        printf("Sum between them: %d\n", sum);
    }

    printf("Array after processing:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%5d", a[i]);
    }
    printf("\n");

    return 0;
}