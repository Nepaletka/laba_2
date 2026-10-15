#include <stdio.h>
#include <time.h>
#include "main.h"
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    //1 stage
    double start_time, end_time, step, precision;
    scanf("%lf %lf %lf %lf", &start_time, &end_time, &step, &precision);

    double radioactivity[100];
    double time[100];

    int N = experiment((double *)&radioactivity, (double *)&time, start_time, end_time, step);
    if (N == 0)
    {
        printf("error: bad experiment size\n");
        return -1;
    }

    add_noise((double *)&radioactivity, N);

    //2 stage
    double decay_time, decay_rate;

    decay_time = nonlinear_equation((double *)&radioactivity, (double *)&time, N, precision);
    decay_rate = linear_equation((double *)&radioactivity, (double *)&time, N);

    //3 stage
    double time_differences;

    time_differences = precision_analysis(radioactivity, (double *)&time, N, precision);
    printf("%lf %lf %lf\n", decay_time, decay_rate, time_differences);
    return 0;
}
