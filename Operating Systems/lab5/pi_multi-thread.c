#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NUM_THREADS 4
#define SEED time(NULL)

int sum = 0;

void *trythis(void *param)
{
    srand(SEED);
    double x, y, z;
    int numDot = atoi(param);

    // Critical part

    for (int t = 0; t < numDot / NUM_THREADS; ++t)
    {
        sleep(0.001);
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        z = x * x + y * y;

        if (z <= 1)
        {
            sum += 1;
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t tid[NUM_THREADS];
    double pi;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&(tid[i]), NULL, trythis, argv[1]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pi = (double)sum / atoi(argv[1]) * 4;
    printf("Approximate PI = %g\n", pi);

    pthread_exit(NULL);
}