#include <math.h>
#include <stdio.h>

int main(void)
{
    double x, eps;

    printf("Enter X and epsilon: ");

    if (scanf("%lf %lf", &x, &eps) != 2) {
        printf("Error: invalid input.\n");
        return 1;
    }

    if (eps <= 0.0) {
        printf("Error: epsilon must be positive.\n");
        return 1;
    }

    double sum = 1.0;
    double term = 1.0;
    double exact = cos(x);

    int n = 1;
    int iterations = 0;

    const int MAX_ITER = 100000;

    while (fabs(term) >= eps) {
        term *= (-x * x) / ((2.0 * n - 1.0) * (2.0 * n));
        sum += term;

        n++;
        iterations++;

        if (iterations >= MAX_ITER) {
            printf("Warning: maximum iteration limit reached.\n");
            break;
        }
    }

    double abs_error = fabs(sum - exact);

    double rel_error;

    if (fabs(exact) > 1e-15) {
        rel_error = abs_error / fabs(exact);
    } else {
        rel_error = abs_error;
    }

    printf("\nResults for variant 3 (cos(x)):\n");
    printf("X                 = %.10f\n", x);
    printf("epsilon           = %.10e\n", eps);
    printf("Series sum        = %.12f\n", sum);
    printf("cos(X)            = %.12f\n", exact);
    printf("Absolute error    = %.12e\n", abs_error);
    printf("Relative error    = %.12e\n", rel_error);
    printf("Iterations        = %d\n", iterations);

    return 0;
}
