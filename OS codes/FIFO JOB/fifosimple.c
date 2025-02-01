#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    int process[n],burst[n];
    printf("\nEnter the processes: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }
    printf("\nEnter the burst times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }
    int wait[n],tat[n];
    wait[0] = 0; 
    int sum = 0;
    for(int i = 1; i < n; i++) {
        wait[i] = burst[i-1]+wait[i-1];
        sum += wait[i];
    }
    for(int i = 0; i < n; i++) {
        tat[i] = wait[i] + burst[i];
    }
    printf("\n");
    printf("Processes\t\tBurst Time\tWait Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
        process[i],burst[i],wait[i],tat[i]);
    }
    printf("\nThe average waiting time is: %f\n",sum/n);
}
