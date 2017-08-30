#include <stdio.h>
#include <math.h>

double solve(double x, double R) {
    double alpha = asin(x / R);
    double beta = asin(R / R); // aka PI
    //printf("here x = %d, R = %d, alpha = %f, beta = %f\n", x, R, alpha, beta);
    return (R * R * (beta - alpha + (sin(2 * beta) - sin(2 * alpha) / 2.0))) / 2.0;
}

int main(void) {
    int t;
    int xc, yc, R;
    int xb, yb, xu, yu;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d %d %d", &xc, &yc, &R);
        scanf(" %d %d %d %d", &xb, &yb, &xu, &yu);
        xb -= xc;
        xu -= xc;
        yb -= yc;
        yu -= yc;

        // right intersection circle and rectangle
        double x = sqrt(1.0 * R * R - 1.0 * yu * yu);

        double res = solve(xb, R);
        double aux = fabs(yu) * fabs(x - xb) + solve(x, R);
        //printf("here res = %f, aux = %f\n", res, aux);
        if (yu > 0) {
            res += aux;
        } else {
            res -= aux;
        }
        printf("Case %d: %.5f\n", caso, res);
    }
    return 0;
}
