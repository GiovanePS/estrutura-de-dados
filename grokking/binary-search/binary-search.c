#include <stdio.h>

#define ARR_LENGTH 5001

int binary_search(int[], int);

int main(void) {
    int arr[ARR_LENGTH];

	// Populating array
    for (int i = 0; i < ARR_LENGTH; i++) {
        arr[i] = i;
    }

    // binary_search(arr, 10);
    // binary_search(arr, 5000);
    // binary_search(arr, 750);
}

// Returns the position of guess in array or -1, if the guess isn't there.
int binary_search(int arr[], int item) {
    int low = 0;
    int high = ARR_LENGTH - 1;
    int mid = 0, guess = 0, steps = 0;

    while (low <= high) {
        steps++;
        mid = (low + high) / 2;
		guess = arr[mid];

        if (guess == item) {
            printf("%d steps.\n", steps);
            printf("The position of guess is %d.\n", mid);
            return mid;
        } else if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d steps.\n", steps);
    printf("There's not element %d in given array.\n", item);
    return -1;
}
