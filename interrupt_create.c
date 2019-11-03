#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"
#include <time.h>

void *interrupt_main(void *arg)
{
	int interrupt_resources[4];
	int i,int_id_start=100;
	time_t t;
	while (1)
	{
		srand(time(0));
		interrupt_resources[0]=int_id_start;
		for (i=1;i<4;i++)
		{
			interrupt_resources[i]= rand()%7;
		}
		printf("\n[thread 2] adding interrupt!\n");
		fflush(stdout);
		enQueue(interrupt_resources);
		sleep(3);
		int_id_start++;
	}
	return 0;
}