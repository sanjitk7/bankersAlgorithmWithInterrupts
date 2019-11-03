#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"

void *interrupt_main(void *arg)
{
	int interrupt_resources[4] = {100, 2, 2, 2};
	while (1)
	{
		printf("\nadding interrupt!\n");
		fflush(stdout);
		enQueue(interrupt_resources);
		sleep(1);
	}
	return 0;
}