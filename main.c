#include <stdio.h>
#include <main.h>

int main()
{
    double start_time, end_time, step, precision;
    scanf("%f %f %f %f", &start_time, &end_time, &step, &precision);

    double radioactivity[100];
    double time[100];

    int N = experiment(&radioactivity, &time, start_time, end_time, step);
    if (N == 0)
    {
        printf("error: bad experiment size\n");
        return -1;
    }
    
    add_noise(&radioactivity, N);
    return 0;
}
