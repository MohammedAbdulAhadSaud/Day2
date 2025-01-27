#include <stdio.h>
#include <stdlib.h>


void merge(int a[], int beg, int mid, int end) {
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LA[10];
    int RA[10];

    for (i = 0; i < n1; i++)
        LA[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RA[j] = a[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = beg;

    while (i < n1 && j < n2) {
        if (LA[i] <= RA[j]) {
            a[k] = LA[i];
            i++;
        } else {
            a[k] = RA[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = LA[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = RA[j];
        j++;
        k++;
    }

  
}

void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int a[10];
    printf("Enter the size of the array: ");
    scanf("%d", &n);

   

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

   
    printf("Before sorting, array elements are:\n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("After sorting, array elements are:\n");
    printArray(a, n);

    
 
    return 0;
}
