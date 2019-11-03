#include <stdio.h>
#include "queue.h"

//int interrupt_resources[SIZE][3];//3 is the number of resources
int front = -1;
int rear = -1;
int interrupt_wait[SIZE][4];

void display()
{
    int i, j;
    printf("\nDISPLAYING INTERRUPT\n");
    if (isEmpty())
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ", front);
        printf("\n interrupt_wait:\n ");
        for (i = front; i != rear + 1; i = (i + 1) % SIZE)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%d \t", interrupt_wait[i][j]);
            }
            printf("\n");
        }
        printf("\n Rear -> %d \n", rear);
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
        printf("\n Interrupt Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        for (i = 0; i < 4; i++)
        {

            interrupt_wait[rear][i] = interrupt_resources[i];
        }
        display();
        printf("\n Inserted Interrupt : %d", interrupt_resources[0]);
    }
}
int* deQueue()
{
    int i,send_top_arr[4];
    if (isEmpty())
    {
        printf("\n Interrupt Queue is empty !! \n");
        return (-1);
    }
    else
    {
        for (i=0;i<4;i++){
            send_top_arr[i]=interrupt_wait[front][i];
        }
        printf("\n Deleted interrupt PID -> %d \n", interrupt_wait[front][0]);
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