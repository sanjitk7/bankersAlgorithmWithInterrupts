#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>

int interrupt_main(){
	while(1){
		printf("Created Interrupt\n");
		sleep(1);
	}
}