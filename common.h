#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <sys/time.h>
#include <string.h>

#define LOG_FILE "bankerintprocess.csv"

struct timeval ct;
void log_message(char event[], char detail[]);
char buf[100];
FILE *logfile;
#endif