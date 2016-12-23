#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int insertionSort(int arr[], int n, int count);
int main() {
	int n = 0;
	int arr[1001];
	int count = 0;
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	for (int i = 2; i <= n; i++) {
		do {
			count = insertionSort(arr, n, count);
		} while (arr[i] < arr[i - 1]);
	}
	printf("%d\n", count);
	/*
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	*/
	return 0;
}

int insertionSort(int arr[], int n, int count) {
	int tmp = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] < arr[i - 1]) {
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			count++;
		}
	}
	return count;
}