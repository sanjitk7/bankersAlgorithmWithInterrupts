#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define SIZE 10

extern int front;
extern int rear;
extern int interrupt_wait[SIZE][4];
// void init();
void enQueue(int interrupt_resources[]);
int* deQueue();
int isEmpty();
int isFull();
void display();
#endif // QUEUE_H_INCLUDED