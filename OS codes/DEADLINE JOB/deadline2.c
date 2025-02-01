#include<stdio.h>
typedef struct {
    int pro_num;
    int profit;
    int deadline;
} Object;
void bubbleSort(Object arr[], int n) {
    for(int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) { 
            if (arr[j].profit < arr[j+1].profit) {
                Object temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("\nEnter the number of process:");
    scanf("%d",&n);
    int p[n];
    int d[n];
    Object objects[n];
    printf("\nEnter the profits: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        objects[i].profit=p[i];
        objects[i].pro_num = i+1;
    }
    printf("\nEnter the deadlines: ");
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
        objects[i].deadline=d[i];
    }
    printf("PROCESS\tPROFIT\tDEADLINES\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d",i+1,p[i],d[i]);
        printf("\n");
    } 
    bubbleSort(objects, n);
    printf("\nSorted Table:\n");
    printf("PROCESS\tPROFIT\tDEADLINES\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d",objects[i].pro_num,objects[i].profit,objects[i].deadline);
        printf("\n");
    }
    int maxd = 0;
    for (int i = 0; i < n; i++) {
        if (objects[i].deadline > maxd) {
            maxd = objects[i].deadline;
        }
    }
    int job[maxd];
    for (int i=0; i<maxd; i++) {
        job[i] = -1;
    }
    int maxp=0;
    for (int i = 0; i < n; i++) {
        for (int j = objects[i].deadline - 1; j >= 0; j--) {
            if (job[j] == -1) {
                job[j] = objects[i].pro_num;
                maxp += objects[i].profit;
                break;
            }
        }
    }
    printf("\nThe max profit is: %d", maxp);
    printf("\nThe jobs are: ");
    for (int i = 0; i < maxd; i++) {
        if (job[i] != -1) {
            printf("{J%d} ", job[i]);
        }
    }
    return 0;
}