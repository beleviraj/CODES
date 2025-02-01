#include<stdio.h>
typedef struct
{   int process_no;
    int burst;
    int wait;
    int tat;
}process;
void bubbleSort(process arr[], int n) {
    for(int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) { 
            if (arr[j].burst > arr[j+1].burst) {
                process temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{   int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    process p[n];
    printf("\nEnter the processes: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &p[i].process_no);
    }
    printf("\nEnter the burst times: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &p[i].burst);
    }
    bubbleSort(p,n);
    p[0].wait=0;
    int sum = p[0].wait;
    for(int i=1;i<n;i++)
    {
        p[i].wait=p[i-1].burst+p[i-1].wait;
    }
    for(int i = 0; i < n; i++)
    {
       p[i].tat=p[i].wait+p[i].burst;
    }
    printf("\n");
    printf("Processes\tBurstTime\tWaitTime\tTurnaroundTime\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].process_no,p[i].burst,p[i].wait,p[i].tat);
    }
    printf("\nThe average waiting time is: %f\n", (float)sum / n);
}

