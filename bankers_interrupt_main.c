#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include "bankers_process.c"
#include "interrupt_create.c"

int main() 
{ 
    pthread_t thread_banker,thread_interrupt; 
    printf("Before Thread\n"); 
    printf("%d Self pthread thread_id\n",pthread_self() );
    pthread_create(&thread_banker, NULL, process_main, NULL); 
    printf("%d Bankers Thread thread_id\n",thread_banker);
    pthread_create(&thread_interrupt,NULL,interrupt_main,NULL);
    printf("%d Interrupt Thread thread_id\n",thread_interrupt);
    pthread_join(thread_banker, NULL);
    pthread_cancel(thread_interrupt);
    printf("After Thread\n"); 
    exit(0); 
}