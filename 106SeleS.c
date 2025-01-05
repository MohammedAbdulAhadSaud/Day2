
#include <stdio.h>
#include <stdlib.h>


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


void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;

 
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

   
    printf("Before sorting, array elements are:\n");
    printArr(a, n);

 
    selectionSort(a, n);

   
    printf("After sorting, array elements are:\n");
    printArr(a, n);

   
    free(a);
    return 0;
}
