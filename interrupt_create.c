#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>
#include "queue.h"

int interrupt_main(){
	int interrupt_resources[4]={100,2,2,2};
	while(1){
		enQueue(interrupt_resources);
	}
	return 0;
}