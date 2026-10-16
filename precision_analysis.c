#include <math.h>
#include <stdio.h>
#include "main.h"

double dev_exp(double *radioactivity, double *time, int M, double decay_time) {
    double sum = 0;
    for (int i = 0; i < M; i++) {
        sum += pow(radioactivity[i] - exp((-1) * time[i] / decay_time), 2);
    }
    sum /= M;
    return sqrt(sum);
}

double dev_linear(double *radioactivity, double *time, int M, double decay_rate) {
    double sum = 0;
    for (int i = 0; i < M; i++) {
        sum += pow((radioactivity[i] - (1.0 - time[i] / decay_rate)), 2);
    }
    sum /= M;
    return sqrt(sum);
}

double precision_analysis(double *radioactivity, double *time, int N, double precision, double  interval1, double interval2) {
    int M = 10;

    double current_decay_time = nonlinear_equation(radioactivity, time, M, precision,  interval1, interval2);
    double current_decay_rate = linear_equation(radioactivity, time, M);

    double deviation1 = dev_exp(radioactivity, time, M, current_decay_time);
    double deviation2 = dev_linear(radioactivity, time, M, current_decay_rate);
    
    while ((M <= N) && (deviation2 / deviation1 < 2.0)) {
        double current_decay_time = nonlinear_equation(radioactivity, time, M, precision,  interval1, interval2);
        double current_decay_rate = linear_equation(radioactivity, time, M);

        // printf("%f %f %f\n", deviation1, deviation2, deviation2 / deviation1);
        deviation1 = dev_exp(radioactivity, time, M, current_decay_time);
        deviation2 = dev_linear(radioactivity, time, M, current_decay_rate);
        
        M++;
    }
    
    if (M > N) {
        return time[N - 1];
    }
    
    return time[M - 1];
}
