#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int numArr1 = 0, numArr2 = 0, arr1[100001], arr2[100001];
	FILE *fp = fopen("input.txt", "r");
	FILE *fd = fopen("output.txt", "w");
	if (fd == NULL) {
		return -1;
	}
	if (fp == NULL) {
		return -1;
	}
	fscanf(fp, "%d", &numArr1);
	for (int i = 1; i <= numArr1; i++) {
		fscanf(fp, "%d", &arr1[i]);
	}
	fscanf(fp, "%d", &numArr2);
	for (int i = 1; i <= numArr2; i++) {
		fscanf(fp, "%d ", &arr2[i]);
	}
	int i = 1, j = 1, k = 1;
	while (i <= numArr1 && j <= numArr2) {
		if (arr1[i] <= arr2[j]) {
			fprintf(fd, "%d ", arr1[i]);
			i++;
		}
		else {
			fprintf(fd, "%d ", arr2[j]);
			j++;
		}
		k++;
	}
	while (i <= numArr1) {
		fprintf(fd, "%d ", arr1[i]);
		i++;
		k++;
	}
	while (j <= numArr2) {
		fprintf(fd, "%d ", arr2[j]);
		j++;
		k++;
	}
	fclose(fp);
	
	fclose(fd);
	
	return 0;

}