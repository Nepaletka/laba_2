#include <stdio.h>
#include <time.h>
#include "main.h"
#include <stdlib.h>

int main()
{
    srand(time(NULL));

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
    return 0;
}
