#include <math.h>
#include <stdlib.h>
#include <time.h>

void add_noise (double *radioactivity, int N){
    const double amplitude = 0.05;

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        radioactivity[i] += amplitude * (rand() / (double) RAND_MAX - 0.5);
    }

}

int experiment (double *radioactivity, double *time, double start_time, double end_time, double step){
    const double R0 = 1.0;
    const double beta = 10.0;
    
    for (double t = start_time, int N = 0, t <= end_time + (step / 10) && N < 100, t += step, N++){
        radioactivity[N] = R0 * exp(- t / beta);
        time[N] = t;
    }

    return n;
}
