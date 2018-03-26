#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>

void *my_threaded_function(void *args)
{

	sleep(5);

	printf("I'm in the thread...\n");

	raise(SIGUSR1);
	
	return NULL;
}

void handle_my_custom_signal(int signal)
{
	printf("Hello :) Good news! I received the signal!\n");
}

int main(int argc, char *argv[]) 
{
	pthread_t my_thread;
	int err;
	int not_so_random_number = 19;

	printf("Shall we begin this experiment?\n");

	if (signal(SIGUSR1  , handle_my_custom_signal) == SIG_ERR) {
		
		printf("\nCan't catch SIGUSR1 \n");
	}

	err = pthread_create(&my_thread, NULL, my_threaded_function, (void *)(intptr_t)not_so_random_number);
	
	if (err != 0) {
		printf("\nWhat?? Can't create thread because of: %s", strerror(err));
	} else {
		printf("\nYas! Thread created successfully\n");
	}
	
	while(1) {
		printf("OLA OLA OLA OLA\n");
		sleep(2);
	}
}
