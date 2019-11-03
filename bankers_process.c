//a circular queue
#include <stdio.h>
#include <unistd.h>
#include "queue.h"

void *process_main(void *arg)
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n, m, i, j, k, x, interrupt_choice,processed_first, temp, interrupt_count = 0, not_en = 0;
    int* temp_arr;
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
                    printf("Process %d is Executed\n", i);
                    //----------------------------------------------------------------------------------------------------------------------------------

                    //dont randomly populate but ask user for hardware interrupt and resources for now
                    /*
                interrupt_choice=0;
                printf("\nDear User Do you want to initiate a hardware interrupt? 1. Yes 2. No\n");
                scanf("%d",&interrupt_choice);
                if (interrupt_choice==1){
                    printf("Enter PID:");
                    scanf("%d",&temp);
                    enQueue(temp);
                    display();
                    ++interrupt_count;
                }
                else{
                    printf("Checking the interrupt queue...\n");
                }
                */

                    //now check if the interrupt wait queue is not empty
                    if (isEmpty())
                    {
                        printf("\nNo waiting interrupt Detected! So resuming execution of safe sequence...");
                    }
                    else
                    {
                        printf("\nInterrupt Detected!");
                        //check if the interrupt can be granted                        
                        processed_first=-1;
                        while(!isEmpty()){
                        
                        temp_arr=deQueue();
                        if (temp_arr[0]==processed_first)
                            break;
                            printf("\nChecking %d Resource Req\n",temp_arr[0]);
                            fflush(stdout);
                            for (x=1;x<m+1;x++){
                                if (interrupt_wait[front][x]>avail[x]){
                                    not_en=1;
                                    break;
                                }
                            if (not_en==1){
                                printf("Interrupt %d Cannot be executed: Not enough resources. Waiting for resources to be freed\n",temp_arr[0]);
                                fflush(stdout);
                                processed_first=temp_arr[0];
                                //enQueue(temp_arr);
                            }
                        
                            if (not_en==0){
                                printf("Interrupt %d is executed now! Resources are used and freed immedietly\n",temp_arr[0]);
                                fflush(stdout);
                                
                        }
                            }
                        }
                        /*for (x=1;x<4;x++){
                            if (interrupt_wait[front][x]>avail[x]){
                                not_en=1;
                                break;
                                }
                            }
                        if (not_en==1)
                            printf("Interrupt Cannot be executed: Not enough resources. Waiting for resources to be freed\n");     
                        
                        if (not_en==0){
                            printf("Interrupt %d is executed now! Resources are used and freed immedietly\n",interrupt_wait[front][0]);
                            deQueue();
                            display();
                        }*/

                        /*if (interrupt_resources>avail)
                        printf("Interrupt cant be executed now it has to wait in queue until resources are freed");
                    else{
                        printf("The interrupt %d is executed.")
                        //remove the interrupt from the interrupt_wait q
                        dequeue()
                    }*/
                        //since interrupt is granted, executed in one go - no need to change the resource part
                    }
                    //------------------------------------------------------------------------------------------------------------------------------------------------------------
                }
            }
        }
        sleep(1);
        fflush(stdout);
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