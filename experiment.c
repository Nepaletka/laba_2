#include <math.h>
#include <stdlib.h>

void add_noise (double *radioactivity, int N){
    const double amplitude = 0.05;
    
    for(int i = 0; i < N; i++){
        radioactivity[i] += amplitude * (rand() / (double) RAND_MAX - 0.5);
    }

}

int experiment (double *radioactivity, double *time, double start_time, double end_time, double step){
    const double R0 = 1.0;
    const double beta = 10.0;

    int N = 0;
    double t = start_time;

    while(t <= end_time + (step / 2) && N < 100){
        time[N] = t;
        radioactivity[N] = R0 * exp(- t / beta);
        t += step;
        N++;
    }

    return N;
}