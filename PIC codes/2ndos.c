#include<stdio.h>
#include<stdlib.h>


int front = -1, rear = -1;
int n = 5;
int q[5];
int startTime[5] = {0};
void mergesort();
void dis();

void enqueue(int c, int start) {
    if (rear == n - 1) {
        printf("\nQUEUE IS FULL!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        q[rear] = c;
    } else {
        rear++;
        q[rear] = c;
    }
    startTime[rear] = start;
   
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else if (front == rear) {
        printf("\nThe Dequeued element is: %d", q[front]);
        front = rear = -1;
    } else {
        printf("\nThe Dequeued element is: %d ", q[front]);
        front++;
    }
   
}

void view() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nPeek element is: %d", q[front]);
    }
}

void dis() {
    int wait = 0;
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nprocess\t\tstart time\twait\n");
        for (int j = front; j <= rear; j++) {
            if (j == front) {
                wait = 0;
            } else {
                wait = startTime[j] + wait;
            }
            printf("[%d]\t\t%d\t\t%d\t\t\n", q[j], startTime[j], wait);
        }
    }
    int lb = 0, ub = n - 1;
    mergesort(startTime, lb, ub, n);
    printf("\n");
    for(int i=0;i<=n;i++){
        printf("%d",startTime[i]);
    }

}

void queue() {
    int y, c, start = 0;
    while (y != 5) {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.VIEW\n4.DISPLAY\n5.EXIT\n");
        printf("\nEnter the operation :");
        scanf("%d", &y);
        switch (y) {
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &c);
                printf("\nEnter the start time: ");
                scanf("%d", &start);
                enqueue(c, start);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                view();
                break;
            case 4:
                dis();
                break;
            case 5:
                exit(0);
                break;
        }
    }
}
void merge(int starttime[], int lb, int mid, int ub, int n) {
    int b[n];
    int i = lb, j = mid + 1, k = lb;

    while (i <= mid && j <= ub) {
        if (starttime[i] < starttime[j]) {
            b[k] = starttime[i];
            i++;
        } else {
            b[k] = starttime[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        while (j <= ub) {
            b[k] = starttime[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = starttime[i];
            i++;
            k++;
        }
    }
    for (int i = lb; i <= ub; i++) {
        starttime[i] = b[i];
    }
}

void mergesort(int starttime[], int lb, int ub, int n) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(starttime, lb, mid, n);
        mergesort(starttime, mid + 1, ub, n);
        merge(starttime, lb, mid, ub, n);
    }
}


int main() {
    int choice;
    while (choice != 3) {
        printf("\n1.QUEUE\n2.EXIT");
        printf("\nEnter the operation : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                queue();
                break;
            case 2:
                exit(0);
                break;
        }
    }

    return 0;
}
