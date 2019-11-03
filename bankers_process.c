//a circular queue
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "queue.h"
#include "common.h"

void *process_main(void *arg)
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n, m, i, j, k, x, interrupt_choice, processed_first, temp, interrupt_count = 0, not_en = 0;
    int *temp_ptr;
    int temp_arr[4];
    n = 5;                         // Number of processes
    m = 3;                         // Number of resources
    int alloc[5][3] = {{0, 1, 0},  // P0    // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4

    int max[5][3] = {{7, 5, 3},  // P0    // MAX Matrix
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    int avail[3] = {3, 3, 2}; // Available Resources

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    { //creation of need matrix
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    { //the loop below doesnt guarentee that all the processes are executed, so the worst case senario for a safe state is that only one process is executed in one iteration
        for (i = 0; i < n; i++)
        { //for each process
            if (f[i] == 0)
            { //thats has not been executed yet

                int flag = 0;
                for (j = 0; j < m; j++)
                { //check for all resources if need is not greater than available
                    if (need[i][j] > avail[j])
                    { //if it is greater then it cant be executed so set flag to 1
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {                   //if the particular process can be executed (need<avail) - execute it
                    ans[ind++] = i; //seperate index ind is used and incremented after assign/"execute" process
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y]; //resource is freed up
                    f[i] = 1;                    //set finish to 1
                    sleep(1);
                    memset(buf,0,99);
                    sprintf(buf,"P%d",i);
                    log_message("PROCESS_EXECUTED",buf);
                    printf("BUFFER:%s",buf);
                    //now check if the interrupt wait queue is not empty
                    log_message("CHECKING_INT_QUEUE","");
                    if (isEmpty())
                    {
                        log_message("FAILED:NO_INTERRUPT","");
                    }
                    else
                    {
                        printf("\n [thread 1] Interrupt Detected!");
                        //check if the interrupt can be granted
                        processed_first = -1;
                        while (!isEmpty())
                        {

                            temp_ptr = deQueue();
                            for (x=0;x<4;x++)
                            {
                                temp_arr[x]= *(int*)(temp_ptr + x);
                            }

                            if (temp_arr[0] == processed_first)
                            {
                                break;
                            }
                            printf("\n[thread 1]Checking %d Resource Req\n", temp_arr[0]);
                            fflush(stdout);
                            //log_message("check_res_req");
                            printf("Available is:");
                            for (x=0;x<3;x++)
                                printf("%d\t",avail[x]);
                            printf("\ntemp_arr:");
                            printf("temp array[0] %d",temp_arr[0]);
                            printf("temp array[1] %d",temp_arr[1]);
                            printf("temp array[2] %d",temp_arr[2]);
                            printf("temp array[3] %d",temp_arr[3]);
                            printf("\n");
                            
                            for (x = 1; x < m + 1; x++)
                            {
                                if (temp_arr[x] > avail[x-1])
                                {
                                    not_en = 1;
                                    break;
                                }
                            }
                            if (not_en == 1)
                            {
                                printf("[th 1]]nterrupt %d Cannot be executed: Not enough resources. Waiting for resources to be freed\n", temp_arr[0]);
                                fflush(stdout);
                                processed_first = temp_arr[0];
                                enQueue(temp_arr);
                            }

                            if (not_en == 0)
                            {
                                printf("[th 1]Interrupt %d is executed now! Resources are used and freed immedietly\n", temp_arr[0]);
                                fflush(stdout);
                            }
                        }
                    }
                }
            }
        }
    }
    /*if (!isEmpty()){
    printf("\nInterrupt %d could not be granted because required resources are too high!!\n",interrupt_wait[front][0]);
} */
    printf("\nSAFE SEQUENCE GENERATED FOR THE PROCESSES IN THE CURRENT STATE IS : \n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);

    return 0;
}