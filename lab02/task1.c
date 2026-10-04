#include <math.h>
#include <stdio.h>

int main(void)
{
    double x_start, x_end, dx;

    printf("Enter Xstart, Xend and dX: ");

    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        printf("Error: invalid input.\n");
        return 1;
    }

    if (x_start >= x_end || dx <= 0.0) {
        printf("Error: Xstart must be less than Xend and dX must be positive.\n");
        return 1;
    }

    printf("\n%12s | %18s\n", "X", "Y(X)");
    printf("-------------------------------\n");

    for (double x = x_start; x <= x_end + 1e-12; x += dx) {
        double y;

        if (x <= 1.0) {
            y = 2.0 * x + 1.0;
        } else if (x <= 3.0) {
            if (fabs(x - 2.0) < 1e-12) {
                printf("%12.4f | %18s\n", x, "[Not defined]");
                continue;
            }

            y = x / (x - 2.0);
        } else {
            y = sqrt(x);
        }

        printf("%12.4f | %18.6f\n", x, y);
    }

    return 0;
}
