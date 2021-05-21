#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct Bank
{
    int balance;
} Bank;

Bank ac;
pthread_mutex_t lock;

void *withDraw(void *amount)
{
    int *temp = (int *)amount;
    if (ac.balance >= *temp)
    {
        pthread_mutex_lock(&lock);
        ac.balance -= *temp;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void *deposit(void *amount)
{
    int *temp = (int *)amount;
    pthread_mutex_lock(&lock);
    ac.balance += *temp;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[2];
    int amount = 10000;
    ac.balance = 0;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }

    pthread_create(&(tid[0]), NULL, deposit, &ac);
    pthread_create(&(tid[1]), NULL, withDraw, &ac);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    printf("Balance is %d\n", ac.balance);
    pthread_mutex_destroy(&lock);

    pthread_exit(NULL);
}