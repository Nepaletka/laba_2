#include <stdio.h>
#include <time.h>
#include "main.h"
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    //1 stage
    double start_time, end_time, step, precision, beta;
    scanf("%lf %lf %lf %lf %lf", &start_time, &end_time, &step, &precision, &beta);

    double radioactivity[100];
    double time[100];

    int N = experiment((double *)&radioactivity, (double *)&time, start_time, end_time, step, beta);
    if (N == 0)
    {
        printf("error: bad experiment size\n");
        return -1;
    }

    add_noise((double *)&radioactivity, N);

    //2 stage
    double decay_time, decay_rate;
    double interval1, interval2;
    scanf("%lf %lf", &interval1, &interval2);

    decay_time = nonlinear_equation((double *)&radioactivity, (double *)&time, N, precision, interval1, interval2);
    decay_rate = linear_equation((double *)&radioactivity, (double *)&time, N);

    //3 stage
    double time_differences;

    time_differences = precision_analysis(radioactivity, (double *)&time, N, precision, interval1, interval2);
    printf("decay_time: %lf\ndecay_rate: %lf\ntime_differences: %lf\n", decay_time, decay_rate, time_differences);
    return 0;
}
