#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void heapify(int arr[], int num, int index);
void swap(int arr[], int num1, int num2);
void heapSort(int arr[], int num);
int main() {
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return -1;
	int num = 0, arr[100000];
	fscanf(fp, "%d", &num);
	for (int i = 0; i < num; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	heapSort(arr, num);
	FILE *fd = fopen("output.txt", "w");
	for (int i = 0; i < num; i++)
		fprintf(fd, "%d ", arr[i]);
	return 0;
}

void heapSort(int arr[], int num) {
	for (int i = num / 2 - 1; i >= 0; i--) 
		heapify(arr, num, i);
	for (int i = num - 1; i >= 0; i--) {
		swap(arr, 0, i);
		heapify(arr, i, 0);
	}

}
void heapify(int arr[], int num, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < num && arr[left] > arr[largest])
		largest = left;
	if (right < num && arr[right] > arr[largest])
		largest = right;
	if (largest != index) {
		swap(arr, index, largest);
		heapify(arr, num, largest);
	}
}
void swap(int arr[], int num1, int num2) {
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}