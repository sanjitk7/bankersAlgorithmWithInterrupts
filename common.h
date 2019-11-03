#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <sys/time.h>
#include<string.h>
struct timeval ct;
void log_message(char event[],char detail[]);
char buf[100];

#endif