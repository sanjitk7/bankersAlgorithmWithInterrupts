#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "common.h"
#include "queue.h"
#include "interrupt_create.h"
#include "bankers_process.h"

int main()
{
    pthread_t thread_banker, thread_interrupt;

    logfile = fopen(LOG_FILE, "w");
    if (logfile == NULL)
    {
        fprintf(stderr, "error opening logfile");
        return 0;
    }

    memset(buf, 0, 99);
    sprintf(buf, "%d", (int)pthread_self());
    log_message("START_PROCESSING", buf);

    pthread_create(&thread_banker, NULL, process_main, NULL);
    memset(buf, 0, 99);
    sprintf(buf, "%d", (int)thread_banker);
    log_message("SAFE_PROCESS_THREAD_START", buf);

    pthread_create(&thread_interrupt, NULL, interrupt_main, NULL);
    memset(buf, 0, 99);
    sprintf(buf, "%d", (int)thread_interrupt);
    log_message("INTERRUPT_THREAD_START", buf);

    pthread_join(thread_banker, NULL);
    pthread_cancel(thread_interrupt);
    log_message("END_PROCESSING", "");

    fclose(logfile);
    printf("AFTER_THREADING\n");
    exit(0);
}
