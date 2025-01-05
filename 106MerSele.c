
#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int beg, int mid, int end) {
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int *LeftArray = (int *)malloc(n1 * sizeof(int)); 
    int *RightArray = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = beg; 

    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        } else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = RightArray[j];
        j++;
        k++;
    }

    free(LeftArray);
    free(RightArray);
}

void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void selectionSort(int a[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("1. Merge Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        printf("Before Sorting:\n");
        printArray(a,n);
            mergeSort(a, 0, n - 1);
            printf("After Merge Sort, array elements are:\n");
            break;
        case 2:
        printf("Before Sorting:\n");
        printArray(a,n);
            selectionSort(a, n);
            printf("After Selection Sort, array elements are:\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printArray(a, n);

    free(a);
    return 0;
}
