//a circular queue
#include <stdio.h>
#define SIZE 5



int interrupt_wait[SIZE][4];
//int interrupt_resources[SIZE][3];//3 is the number of resources
int front = -1, rear =-1;
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void enQueue(int element)
{
    int i=0;
    if(isFull()) printf("\n Interrupt Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        interrupt_wait[rear][0] = element;
        printf("\nEnter the resources required for the initiated hardware interrupt:\n");
                    for (i=1;i<4;i++) {
                        scanf("%d",&interrupt_wait[rear][i]);
                    }//3 is number of resources
                }
        printf("\n Inserted -> %d", element);
    }


int deQueue()
{
    int element;
    if(isEmpty()) {
        printf("\n Interrupt Queue is empty !! \n");
        return(-1);
    } else {
        element = interrupt_wait[front][0];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted interrupt PID -> %d \n", element);
        return 0;
    }
}
void display()
{
    int i,j;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n interrupt_wait:\n ");
        for( i = front; i!=rear+1; i=(i+1)%SIZE) {
            for (j=0;j<4;j++){
            printf("%d \t",interrupt_wait[i][j]);
        }
        printf("\n");
    }
        printf("\n Rear -> %d \n",rear);
    }
}

int process_main(){ 
    // P0, P1, P2, P3, P4 are the Process names here 
  
    int n, m, i, j, k, x,interrupt_choice,temp,interrupt_count=0,not_en=0;
    n = 5; // Number of processes 
    m = 3; // Number of resources 
    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix 
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
  
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix 
                      { 3, 2, 2 }, // P1 
                      { 9, 0, 2 }, // P2 
                      { 2, 2, 2 }, // P3 
                      { 4, 3, 3 } }; // P4 
  
    int avail[3] = { 3, 3, 2 }; // Available Resources 
  
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m]; 
    for (i = 0; i < n; i++) { //creation of need matrix
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { //the loop below doesnt guarentee that all the processes are executed, so the worst case senario for a safe state is that only one process is executed in one iteration
        for (i = 0; i < n; i++) { //for each process
            if (f[i] == 0) { //thats has not been executed yet
  
                int flag = 0; 
                for (j = 0; j < m; j++) { //check for all resources if need is not greater than available
                    if (need[i][j] > avail[j]){ //if it is greater then it cant be executed so set flag to 1
                        flag = 1;
                         break; 
                    } 
                } 
  
                if (flag == 0) { //if the particular process can be executed (need<avail) - execute it
                    ans[ind++] = i; //seperate index ind is used and incremented after assign/"execute" process
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; //resource is freed up
                    f[i] = 1; //set finish to 1
                    printf("Process %d is Executed\n",i);
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
                if (isEmpty()){
                    printf("\nNo waiting interrupt Detected! So resuming execution of safe sequence...");
                }
                else{
                    printf("\nInterrupt Detected!");
                    //check if the interrupt can be granted

                        /*for (x=1;x<4;x++){
                            if (interrupt_wait[front][i]>avail[i]){
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
if (!isEmpty()){
    printf("\nInterrupt %d could not be granted because required resources are too high!!\n",interrupt_wait[front][0]);
} 
    printf("\nSAFE SEQUENCE GENERATED FOR THE PROCESSES IN THE CURRENT STATE IS : \n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
  
    return (0); 
  
    // This code is contributed by Deep Baldha (CandyZack) 
}