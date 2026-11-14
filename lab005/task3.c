#include <stdio.h>
#include <stddef.h>

int sum_above_average(const double *data, size_t count,
                      double *average, double *result)
{
    if (data == NULL || average == NULL ||
        result == NULL || count == 0) {
        return 1;
    }

    const double *end = data + count;
    double total = 0.0;

    for (const double *ptr = data; ptr < end; ptr++) {
        total += *ptr;
    }

    double mean = total / (double)count;
    double sum = 0.0;

    for (const double *ptr = data; ptr < end; ptr++) {
        ptrdiff_t i = ptr - data;

        if (*(data + i) > mean) {
            sum += *(data + i);
        }
    }

    *average = mean;
    *result = sum;

    return 0;
}

int main(void)
{
    double data[] = {2.0, 4.0, 6.0, 8.0, 10.0};
    size_t count = sizeof(data) / sizeof(*data);
    double average = 0.0;
    double result = 0.0;

    printf("Array: ");

    for (const double *ptr = data; ptr < data + count; ptr++) {
        printf("%.2f ", *ptr);
    }

    printf("\n");

    if (sum_above_average(data, count, &average, &result) != 0) {
        printf("Error: invalid pointers or empty array.\n");
        return 1;
    }

    printf("Average = %.2f\n", average);
    printf("Sum above average = %.2f\n", result);

    return 0;
}