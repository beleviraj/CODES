#include <stdio.h>

#define MEMORY 100
int OS = 60;
#define UP 40
int FIX_FRAMES = 60 / 5;

void display(int n, int p[], int s[], int frames[], int j, int wait_processes[]);
void mft(int n, int p[], int s[]) {
    int frames[n];
    int wait_processes[n];
    int j = 0;
    int remaining_memory = MEMORY - OS;
    
    for (int i = 0; i < n; i++) {
        frames[i] = s[i] / 5;
        if (s[i] % 5 != 0) {
            frames[i]++;
        }
        if ( FIX_FRAMES<=0 || frames[i] > FIX_FRAMES) {
            wait_processes[j] = p[i];
            j++;
        } else {
            FIX_FRAMES-=frames[i];
        }
    }
    display(n, p, s, frames, j, wait_processes);
}

void mvt(int n,int p[],int s[]){
    int w[n],j=0;
    for(int i=0;i<n;i++)
    {
        if(OS<=0){
             w[j]=p[i];
             j++;
        }
        else{
            OS-=s[i];
        }
    }
    printf("\nProcess\tSize\n");
    for (int i = 0; i < n; i++) 
    {
        printf("p%d\t%d\n", p[i], s[i]);
    }

    printf("Waiting processes: ");
    for (int i = 0; i < j; i++) {
        printf("p%d ",w[i] );
    }
}
void display(int n, int p[], int s[], int frames[], int j, int wait_processes[]) {
    printf("\nProcess\tSize\tFrames\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\n", p[i], s[i], frames[i]);
    }

    printf("Waiting processes: ");
    for (int i = 0; i < j; i++) {
        printf("p%d ", wait_processes[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n];
    printf("Enter the process names: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }
    int size[n];
    printf("Enter the memory size for each process: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
    }
    int choice;
    while(choice!=3){
        printf("\n1.MEMORY FIXED PARTITION\n2.MEMORY VARIABLE PARTITION\n3.EXIT\n");
        printf("\nEnter the choice of memory allocation algorithm: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:mft(n,process,size);
                break;
            case 2:mvt(n,process,size);
                break;
            case 3:return 0;
        }
    }
    return 0;
}
