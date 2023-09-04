#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Bucket Sort Function
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucket[max + 1];
    for (int i = 0; i <= max; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }
}

// Radix Sort Function
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

// Function to accept and display student marks using switch case
void acceptAndDisplayMarks() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nChoose sorting method:\n");
    printf("1. Bucket Sort\n");
    printf("2. Radix Sort\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bucketSort(marks, n);
            printf("\nSorted marks using Bucket Sort:\n");
            break;
        case 2:
            radixSort(marks, n);
            printf("\nSorted marks using Radix Sort:\n");
            break;
        default:
            printf("\nInvalid choice.\n");
            return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");
}

int main() {
    acceptAndDisplayMarks();
    return 0;
}
