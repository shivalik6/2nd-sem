//write a c program to merge two arrays if they are of same size sort the arrays in descending order when merging. if the arrays are of different size print -1 take arrays from user input 
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge_and_sort(int arr1[], int arr2[], int n1, int n2, int merged[]) {
    int i, j, k;

    // Merge arrays (without sorting yet)
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] >= arr2[j]) { // >= for descending order
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements if any
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    // Sort the merged array in descending order
    for (i = 0; i < n1 + n2 - 1; i++) {
        for (j = 0; j < n1 + n2 - i - 1; j++) {
            if (merged[j] < merged[j + 1]) { // < for descending order
                swap(&merged[j], &merged[j + 1]);
            }
        }
    }
}

int main() {
    int arr1[50], arr2[50], merged[100];
    int n1, n2, i;

    printf("Enter the size of the first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements for the first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements for the second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    if (n1 != n2) {
        printf("-1\n");
        return 0;
    }

    merge_and_sort(arr1, arr2, n1, n2, merged);

    printf("Merged array in descending order:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
