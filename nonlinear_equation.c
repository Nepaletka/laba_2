#include<stdio.h>
#include <math.h>

double equation_value(double decay_time, double *radioactivity, double *time, int N) {
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        double e = exp(-time[i] / decay_time);
        sum += time[i] * e * (radioactivity[i] - e);
    }
    return sum;
}

double nonlinear_equation(double *radioactivity, double *time, int N, double precision) {
    double interval1, interval2;
    scanf("%lf %lf", &interval1, &interval2);

    double a = interval1, b = interval2;
    double fa = equation_value(a, radioactivity, time, N);

    while (b - a > precision) {
        double c = (a + b) / 2.0;
        double fc = equation_value(c, radioactivity, time, N);

        if (fc == 0.0) {
            return c;
        }
        if (fa * fc < 0.0) {
            b = c;             
        } else {
            a = c;            
            fa = fc;
        }
    }
    return (a + b) / 2.0;
}
