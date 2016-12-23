#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int partialSort(int arr[], int size)
{
	int i, key, j, count = 0;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			count++;
		}
		arr[j + 1] = key;
	}
	return count;
}

void insertionSort(int arr[], int size, int k)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		if (partialSort(arr, size) == 0)
			return;
	}
}

int main() {
	FILE *fp = fopen("input.txt", "r");
	FILE *ofp = fopen("output.txt", "w");
	if (fp == NULL || ofp == NULL)
		return -1;
	int n = 0, k = 0, arr[100000];
	fscanf(fp, "%d ", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%d ", &arr[i]);
		//printf("%d ", arr[i]);
	}
	fscanf(fp, "%d ", &k);
	insertionSort(arr, n, k);
	for (int i = 1; i <= k; i++)
		fprintf(ofp, "%d ", arr[i]);
	return 0;
}