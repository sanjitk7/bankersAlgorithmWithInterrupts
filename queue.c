#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "common.h"

//int interrupt_resources[SIZE][3];//3 is the number of resources
int front = -1;
int rear = -1;
int interrupt_wait[SIZE][4];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void display()
{
    int i, j;
    printf("\n[%d] DISPLAYING INTERRUPT\n", (int)pthread_self());
    if (isEmpty())
        printf(" \n[%d] QUEUE IS EMPTY!\n", (int)pthread_self());
    else
    {
        printf("\n[%d] FRONT : %d\n", (int)pthread_self(), front);
        printf("[%d] INTERRUPT_WAIT: ", (int)pthread_self());
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%d \t", interrupt_wait[i][j]);
            }
            printf("\n");
        }
        printf("\n[%d] REAR :%d\n", (int)pthread_self(), rear);
        fflush(stdout);
    }
}

int topInterruptId()
{
    if (isEmpty())
    {
        return (-1);
    }
    else
    {
        return interrupt_wait[front][0];
    }
}

int getSize()
{
    if (front == -1 && rear == -1)
    {
        return 0;
    }
    else if (front == rear)
    {
        return 1;
    }
    else
    {
        return abs(front - rear);
    }
}
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
void enQueue(int interrupt_resources[])
{
    int i = 0;

    if (isFull())
        printf("\n[th q] INTERRUPT QUEUE IS FULL! \n");
    else
    {
        pthread_mutex_lock(&mutex);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        for (i = 0; i < 4; i++)
        {

            interrupt_wait[rear][i] = interrupt_resources[i];
        }
        pthread_mutex_unlock(&mutex);
        display();
        printf("\n[th q] INTERRUPT INSERTED IS : %d", interrupt_resources[0]);
    }
}
int *deQueue()
{
    int i, send_top_arr[4];
    if (isEmpty())
    {
        printf("\n[th q] INTERRUPT QUEUE IS EMPTY! \n");
        return NULL;
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            send_top_arr[i] = interrupt_wait[front][i];
        }
        printf("\n[th q] INTERRUPT DEQUEUED IS : %d \n", interrupt_wait[front][0]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else
        {
            front = (front + 1) % SIZE;
        }
        return send_top_arr;
    }
}