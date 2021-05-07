#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double countPi(char *numRun)
{
    srand(time(NULL));
    int i, dotInCircle;
    double x, y, z, pi;
    int allDot = atoi(numRun);

    dotInCircle = 0;
    //Critical part
    for (i = 0; i < allDot; ++i)
    {
        sleep(0.001);
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        z = x * x + y * y;

        if (z <= 1)
            dotInCircle++;
    }

    pi = (double)dotInCircle / allDot * 4;
    return pi;
}

int main(int argc, char *argv[])
{
    printf("Approximate PI = %g\n", countPi(argv[1]));
    return (0);
}