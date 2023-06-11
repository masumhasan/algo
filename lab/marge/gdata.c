
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);


int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    double time_taken;

    generateRandomArray(arr, n);

    printf("Original array:\n");
    printArray(arr, n);

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %f seconds\n", time_taken);

    // Additional code to repeat the experiment for different values of n and plot the graph

    return 0;
}



void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}




void merge(int arr[], int start, int mid, int end) {
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int leftArray[size1];
    int rightArray[size2];

    int i, j, k;
    for (i = 0; i < size1; i++) {
        leftArray[i] = arr[start + i];
    }
    for (j = 0; j < size2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < size1 && j < size2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}



void generateRandomArray(int arr[], int size) {
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

