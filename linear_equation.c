#include "main.h"
double linear_equation(double *radioactivity, double *time, int N) {
    double decate_rate, sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += time[i] * time[i];
        sum2 += time[i] * (1 - radioactivity[i]);
    }

    decate_rate = sum1 / sum2;
    return decate_rate;
}
