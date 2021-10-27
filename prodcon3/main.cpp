#include <QCoreApplication>

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define MAX 1

int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value) {
        buffer[fill] = value;
        fill = (fill + 1) % MAX;
}

int get() {
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    return tmp;
}

int loops = 0;

sem_t empty;
sem_t full;

void *producer(void *arg)
{
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&empty);
        put(i);
        sem_post(&full);
    }
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i  < loops; i++) {
        sem_wait(&full);
        int b = get();
        sem_post(&empty);
        printf("%d\n", b);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Needs 2nd arg for loop count variable.\n");
        return 1;
    }

    loops = atoi(argv[1]);

    sem_init(&empty,0, MAX);
    sem_init(&full, 0, 0);

    pthread_t pThread, cThread;
    pthread_create(&pThread, 0, producer, 0);
    pthread_create(&cThread, 0, consumer , 0);
    pthread_join(cThread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
