#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merges(int arr[], int left, int middle, int right);
void mergesort(int arr[], int left, int right);

int main() {
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return -1;
	int num = 0, arr[100000];
	fscanf(fp, "%d", &num);
	for (int i = 0; i < num; i++)
		fscanf(fp, "%d", &arr[i]);

	mergesort(arr, 0, num-1);

	FILE *fd = fopen("output.txt", "w");
	if (fd == NULL)
		return -1;
	for (int i = 0; i < num; i++)
		fprintf(fd, "%d ", arr[i]);
	
	return 0;
}
void mergesort(int arr[], int left, int right) {
	if (left < right) {
		int middle = (left + right - 1) / 2;
		mergesort(arr, left, middle);
		mergesort(arr, middle + 1, right);
		merges(arr, left, middle, right);
	}

}
void merges(int arr[], int left, int middle, int right) {
	int i=0, j=0, k = 0;
	int a1 = middle - left + 1;
	int a2 = right - middle;

	int Left[50000], Right[50000];
	for (i = 0; i < a1; i++)
		Left[i] = arr[left + i];
	for (j = 0; j < a2; j++)
		Right[j] = arr[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < a1 && j < a2) {
		if (Left[i] <= Right[j]) {
			arr[k] = Left[i];
			i++;
		}
		else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < a1) {
		arr[k] = Left[i];
		i++;
		k++;
	}
	while (j < a2) {
		arr[k] = Right[j];
		j++;
		k++;
	}
}