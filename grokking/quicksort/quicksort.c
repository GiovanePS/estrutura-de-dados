#include <stdio.h>

int swap(int *, int *);
int partition(int[], int, int);
void quicksort(int [], int, int);

int main(void) {
	int arr[] = {4, 2, 5, 3, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

int partition(int arr[], int low, int high) {
	int p = arr[low];
	int i = low;
	int j = high;

	while (i < j) {
		while (arr[i] <= p && i <= high - 1) {
			i++;
		}

		while (arr[i] > p && i >= high + 1) {
			j--;
		}

		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[low], &arr[j]);
	return j;

	return 0;
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
