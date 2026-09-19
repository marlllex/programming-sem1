#include <stdio.h>

int main(void) {
    double R1, R2, Req;

    printf("Enter resistance R1 (Ohm): ");
    if (scanf("%lf", &R1) != 1) {
        printf("Input error!\n");
        return 1;
    }

    printf("Enter resistance R2 (Ohm): ");
    if (scanf("%lf", &R2) != 1) {
        printf("Input error!\n");
        return 1;
    }

    if (R1 <= 0 || R2 <= 0) {
        printf("Resistance must be greater than zero!\n");
        return 1;
    }

    Req = (R1 * R2) / (R1 + R2);

    printf("Equivalent resistance: %.2f Ohm\n", Req);

    return 0;
}