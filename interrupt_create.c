#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"
#include <time.h>
#include "common.h"

void *interrupt_main(void *arg)
{
	struct timeval rt;
	int interrupt_resources[4];
	int i,temp_rand,int_id_start=100;
	while (1)
	{
		temp_rand=0;
		gettimeofday(&rt,NULL);
		srand(ct.tv_sec*1000000+ct.tv_usec);
		interrupt_resources[0]=int_id_start;
		for (i=1;i<4;i++)
		{
			interrupt_resources[i]= rand()%7;
		}
		memset(buf,0,99);
		sprintf(buf,"%d",(int)pthread_self());
		log_message("INTERRUPT_ADDED",buf);
		fflush(stdout);
		enQueue(interrupt_resources);
		while(temp_rand==0){
			temp_rand=rand()%3;
		}
		sleep(temp_rand);
		int_id_start++;
	}
	return 0;
}