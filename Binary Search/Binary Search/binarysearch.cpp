#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int num);
int main() {
	int n = 0, m = 0;
	int N[100001];
	int M[100001];
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return -1;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%d ", &N[i]);
	}
	printf("\n ");
	for (int i = 1; i <= m; i++) {
		fscanf(fp, "%d ", &M[i]);

	}
	printf("\n ");
	fclose(fp);
	
	FILE *fp1 = fopen("output.txt", "w+");
	//printf("n: %d, m: %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		fprintf(fp1, "%d ", binarySearch(N,n,M[i]));
	}
	fclose(fp1);
	printf("\n");
	return 0;
}


int binarySearch(int arr[], int size, int num) {
	int lowerBound = 1, upperBound = size;
	int midPoint = lowerBound + (upperBound - lowerBound) / 2;
	for (int j = 1; j <= size; j++) {
		//printf("n: %d", N[i]);
		if (upperBound < lowerBound)
			return -1;
		else if (arr[j] < num) {
			lowerBound = midPoint + 1;
		}
		else if (arr[j] > num) {
			upperBound = midPoint - 1;
		}
		else if (arr[j] == num) {
			return j;
		}
	}
}