#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

const int NUM_THREADS = 8;

struct thread_data {
    int thread_id;
    int sum;
    char *message;
};

struct thread_data thread_data_array[8];

char *messages[8];

void *PrintHello(void *threadarg)
{
    int taskid, sum;
    char *hello_msg;
    struct thread_data *my_data;

    sleep(1);
    my_data = (struct thread_data *) threadarg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    hello_msg = my_data->message;
    printf("Thread %d: %s Sum=%d\n", taskid, hello_msg, sum);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    long taskids[NUM_THREADS ];
    int rc, t, sum;

    sum = 0;
    messages[0] = "English: Hello World!";
    messages[1] = "French: Bonjour le monde!";
    messages[2] = "Spanish: Hola al mundo!";
    messages[3] = "Klingon: Nuq neH!";
    messages[4] = "German: Guten Tag, welt!";
    messages[5] = "Russian: Zdravstvuyte, mir!";
    messages[6] = "Japan: Sekai e konnichiwa!";
    messages[7] = "Latin: Orbis, te saluto!";

    for(t = 0; t < NUM_THREADS; t++) {
        sum += t;
        thread_data_array[t].thread_id = t;
        thread_data_array[t].sum = sum;
        thread_data_array[t].message = messages[t];

        printf("Creating thread %ld\n", t);

        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_data_array[t]);

        if (rc) {
            printf("ERROR, return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);

    return 0;
}

