#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE *fp = fopen("input.txt", "r");
	int num = 0, arr[100000], inversions = 0;
	if (fp == NULL)
		return -1;
	fscanf(fp, "%d", &num);
	for (int i = 1; i <= num; i++)
		fscanf(fp, "%d", &arr[i]);
	for (int i = 1; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			if (arr[j] < arr[i])
				inversions++;
		}
	}
	printf("%d\n", inversions);

	return 0;
}