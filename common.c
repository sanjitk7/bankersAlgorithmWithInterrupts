#include <stdio.h>
#include "common.h"
#include <pthread.h>

void log_message(char event[], char detail[])
{
    gettimeofday(&ct, NULL);
    printf("\nLOG: [%d] %ld %s-%s\n", (int)pthread_self(), ct.tv_sec * 1000000 + ct.tv_usec, event, detail);
    fprintf(logfile, "%d,%ld,%s,%s\n", (int)pthread_self(), ct.tv_sec * 1000000 + ct.tv_usec, event, detail);
}