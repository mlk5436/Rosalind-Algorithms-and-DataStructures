#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void partition(int arr[], int low, int high);
void swap(int arr[], int num1, int num2);

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

	partition(arr, low, high);

	return 0;
}

void partition(int arr[], int low, int high) {
	int num = high;
	if (high - low <= 1) {
		if (arr[high] < arr[low]) 
			swap(arr, high, low);
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
	FILE *fd = fopen("output.txt", "w");
	for (int i = 1; i <= num; i++) {
		fprintf(fd, "%d ", arr[i]);
	}
}

void swap(int arr[], int num1, int num2) {
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}