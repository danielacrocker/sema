// thread0.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *worker_thread(void *arg)
{
	printf("This is worker_thread #%ld\n", (long) arg);
	pthread_exit(NULL);
}

const int N = 5;

// *****

int main()
{
	pthread_t my_thread[N];

	long id;

	for(id = 1; id <= N; id++) 
	{
		int ret = pthread_create(&my_thread[id], NULL, &worker_thread, (void *) id);

		if(ret != 0)
		{
			printf("Error: pthread_create() failed\n");
			exit(EXIT_FAILURE);
		}
	}

	pthread_exit(NULL);
}
