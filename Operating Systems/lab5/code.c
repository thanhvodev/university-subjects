#include <stdio.h>
#include <pthread.h>

int isPrinted[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct thread_data
{
    int thread_id;
};

void *hello(void *id)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)id;

    for (int i = 0; i < my_data->thread_id; i++)
    {
        while (isPrinted[i] == 0)
            ;
    }

    printf("Hello from thread %d\n", my_data->thread_id);
    isPrinted[my_data->thread_id] = 1;

    pthread_exit(NULL);
}

int main()
{

    pthread_t tid[10];
    struct thread_data thread_data_arr[10];
    for (int i = 0; i < 10; i++)
    {
        thread_data_arr[i].thread_id = i;
        pthread_create(&tid[i], NULL, hello, (void *)&thread_data_arr[i]);
    }
    pthread_exit(NULL);
}
