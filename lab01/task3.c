#include <stdio.h>

int main(void) {
    double r1, r2;
    double req;

    printf("Enter R1 (Ohm): ");
    if (scanf("%lf", &r1) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter R2 (Ohm): ");
    if (scanf("%lf", &r2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (r1 <= 0 || r2 <= 0) {
        printf("Resistance must be greater than zero.\n");
        return 1;
    }

    req = (r1 * r2) / (r1 + r2);

    printf("Equivalent resistance: %.2f Ohm\n", req);

    return 0;
}

