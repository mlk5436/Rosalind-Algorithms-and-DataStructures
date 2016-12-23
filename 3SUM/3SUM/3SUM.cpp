#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int x = INT_MAX, y = INT_MAX, z = INT_MAX;

void swap(int arr[], int num1, int num2) {
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
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

void quicksort(int arr[], int low, int high) {
	if (low >= high)
		return;
	int i = 0, j = 0;

	partition(arr, low, high, i, j);

	quicksort(arr, low, i);
	quicksort(arr, j, high);

}
void threeSum(int arr[], int numEle) {
	//printf("called\n");
	int j, k;
	quicksort(arr, 1, numEle);

	for (int i = 1; i <= numEle-2; i++) {
			j = i + 1;
			k = numEle;
			while (j < k) {
				if (arr[i] + arr[j] + arr[k] == 0) {
					//printf("%d %d %d, %d %d %d", i, j, k, arr[i], arr[j], arr[k]);
					x = i;
					y = j;
					z = k;
					return;
				}
				else if (arr[i] + arr[j] + arr[k] < 0)
					j++;
				else
					k--;
			}
		
	}

}
int findIndex(int arr[], int nonSort[],int numEle, int num) {
	for (int j = 1; j <= numEle; j++) {
		if (nonSort[j] == arr[num]) {
			return j;
		}
	}
}
int main() {
	FILE *fp = fopen("input.txt", "r");
	FILE *ofp = fopen("output.txt", "w");
	if (fp == NULL || ofp == NULL)
		return -1;
	int numArr = 0, numEle = 0, arr[10000], nonSort[10000];
	fscanf(fp, "%d %d", &numArr, &numEle);
	for (int i = 1; i <= numArr; i++) {
		for (int j = 1; j <= numEle; j++) {
			fscanf(fp, "%d ", &arr[j]);
			nonSort[j] = arr[j];

		}
		threeSum(arr, numEle);
		//printf("\n\n");
		if (x != INT_MAX && y != INT_MAX && z != INT_MAX) {
			x = findIndex(arr, nonSort, numEle, x);
			y = findIndex(arr, nonSort, numEle, y);
			z = findIndex(arr, nonSort, numEle, z);
			int answer[4] = { 0, x, y, z };
			quicksort(answer, 1, 3);
			fprintf(ofp, "%d %d %d \n", answer[1], answer[2], answer[3]);
		}
		else
			fprintf(ofp, "%d \n", -1);
		x = INT_MAX;
		y = INT_MAX;
		z = INT_MAX;
	}

	return 0;
}

