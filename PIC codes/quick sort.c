#include <stdio.h>

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb], start = lb, end = ub;

    while (start < end) {
        while (arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end; 
}

void quicksort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int lb = 0, ub = n - 1;
    quicksort(a, lb, ub);

    printf("\nThe sorted array is = ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }

    return 0;
}
