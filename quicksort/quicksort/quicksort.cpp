#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void partition(int arr[], int low, int high, int &i, int &j);
void swap(int arr[], int num1, int num2);
void quicksort(int arr[], int low, int high);

int main() {
	FILE *fp = fopen("input.txt", "r");
	int num = 0;
	int arr[100000];
	if (fp == NULL) {
		return -1;
	}
	fscanf(fp, "%d", &num);
	for (int i = 1; i <= num; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	int low = 1, high = num;

	quicksort(arr, 1, num);
	FILE *fd = fopen("output.txt", "w");
	for (int i = 1; i <= num; i++) {
		fprintf(fd, "%d ", arr[i]);
	}
	return 0;
}
void quicksort(int arr[], int low, int high) {
	if (low >= high)
		return;
	int i = 0, j = 0;
	
	partition(arr, low, high, i, j);

	quicksort(arr, low, i);
	quicksort(arr, j, high);

}
void partition(int arr[], int low, int high, int &i, int &j) {
	int num = high;
	if (high - low <= 1) {
		if (arr[high] < arr[low])
			swap(arr, high, low);
		j = high;
		i = low;
		return;
	}
	int mid = low;
	int pivot = arr[low];
	while (mid <= high) {
		if (arr[mid] < pivot)
			swap(arr, low++, mid++);
		else if (arr[mid] == pivot)
			mid++;
		else if (arr[mid] > pivot)
			swap(arr, mid, high--);
	}
	i = low - 1;
	j = mid;
}

void swap(int arr[], int num1, int num2) {
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}

