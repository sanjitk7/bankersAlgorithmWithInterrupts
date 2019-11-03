#include <stdio.h>
#include<stdlib.h>
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
    printf("\n[th %d] DISPLAYING INTERRUPT\n",(int)pthread_self());
    if (isEmpty())
        printf(" \n[th ] Empty Queue\n");
    else
    {
        printf("\n[th %d] Front -> %d ",(int)pthread_self(),front);
        printf("\n[th %d] interrupt_wait:\n ",(int)pthread_self());
        for (i = front; i != rear + 1; i = (i + 1) % SIZE)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%d \t", interrupt_wait[i][j]);
            }
            printf("\n");
        }
        printf("\n[th q] Rear -> %d \n", rear);
    }
}

int topInterruptId(){
    if (isEmpty())
    {
        return (-1);
    }
    else{
        printf("interrupt_wait[front][0] : %d",interrupt_wait[front][0]);
        return interrupt_wait[front][0];
    }
}

int getSize()
{
    printf("front :%d \trear:%d\n",front,rear);
    if (front==-1 && rear==-1)
    {
        return 0;
    }
    else if (front==rear)
    {
        return 1;
    }
    else
    {
        return abs(front-rear);
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
        printf("\n[th q] Interrupt Queue is full!! \n");
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
        printf("\n[th q] Inserted Interrupt : %d", interrupt_resources[0]);
    }
}
int* deQueue()
{
    int i,send_top_arr[4];
    if (isEmpty())
    {
        printf("\n[th q] Interrupt Queue is empty !! \n");
        return (-1);
    }
    else
    {
        for (i=0;i<4;i++){
            send_top_arr[i]=interrupt_wait[front][i];
        }
        printf("\n[th q] From QUEQUE Deleted interrupt PID -> %d \n", interrupt_wait[front][0]);
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