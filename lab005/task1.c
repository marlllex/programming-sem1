#include <stdio.h>
#include <math.h>

int cartesian_to_polar(const double *x, const double *y,
                       double *radius, double *angle)
{
    if (x == NULL || y == NULL ||
        radius == NULL || angle == NULL) {
        return 1;
    }

    if (!isfinite(*x) || !isfinite(*y)) {
        return 1;
    }

    /* У початку координат полярний кут не визначений. */
    if (*x == 0.0 && *y == 0.0) {
        return 1;
    }

    double r = hypot(*x, *y);
    double phi = atan2(*y, *x);

    if (!isfinite(r)) {
        return 1;
    }

    *radius = r;
    *angle = phi;

    return 0;
}

int main(void)
{
    double x, y;
    double radius = 0.0;
    double angle = 0.0;

    printf("Enter X and Y: ");

    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Input error.\n");
        return 1;
    }

    int status = cartesian_to_polar(&x, &y, &radius, &angle);

    if (status != 0) {
        printf("Error: invalid coordinates or pointers.\n");
        return 1;
    }

    printf("Radius R = %.6f\n", radius);
    printf("Angle phi = %.6f radians\n", angle);

    return 0;
}