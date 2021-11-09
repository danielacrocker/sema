// thread_exit.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *worker_thread(void *arg)
{
	pthread_exit((void*)911);
}

// *****

int main()
{
	int i;

	pthread_t thread;

	pthread_t my_thread;

	pthread_create(&thread, NULL, worker_thread, NULL);

	pthread_join(thread, (void **)&i);
	printf("%d\n", i);  // print out 911

	return 0;
}
