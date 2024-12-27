#include <stdio.h>

void selection_sort(int *, int);

int main(void) {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;

        // To found the smallest element of array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}
