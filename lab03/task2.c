#include <stdio.h>

#define ROWS 3
#define COLS 5

void print_matrix(int a[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int a[ROWS][COLS] = {
        {4, -2, 7, 1, -5},
        {8, 3, -1, 6, 4},
        {-6, 2, 5, -3, 1}
    };

    int row_sums[ROWS] = {0};

    printf("Initial matrix:\n");
    print_matrix(a);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            row_sums[i] += a[i][j];
        }

        printf("Row %d sum: %d\n",
               i + 1, row_sums[i]);
    }

    int max_row = 0;

    for (int i = 1; i < ROWS; ++i) {
        if (row_sums[i] > row_sums[max_row]) {
            max_row = i;
        }
    }

    printf("Selected row: %d; sum: %d\n",
           max_row + 1, row_sums[max_row]);

    for (int j = 0; j < COLS; ++j) {
        a[max_row][j] = -a[max_row][j];
    }

    printf("Matrix after processing:\n");
    print_matrix(a);

    return 0;
}
