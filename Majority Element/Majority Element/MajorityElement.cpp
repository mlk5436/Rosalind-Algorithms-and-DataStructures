#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int lines = 0, elements = 0, count = 0, max = 0, mode = 0, modeNum = 0;
	int element[10001], modes[10001];
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL)
		return 0;
	fscanf(fp, "%d %d", &lines, &elements);
	for (int i = 0; i <= elements; i++) {
		element[i] = 0;
	}

	for (int j = 1; j <= lines; j++) {
		for (int i = 1; i <= elements; i++) {
			fscanf(fp, "%d", &element[i]);
		}
		for (int i = 1; i <= elements; i++) {
			for (int k = 1; k <= elements; k++) {
				if (element[i] == element[k])	// iterating from i to n-i elements to count same element
					count++;
			}
			if (count > max) {
				max = count;
				mode = element[i];
			}
			count = 0;
		}
		modeNum++;
		modes[modeNum] = mode;
		max = 0;
		mode = 0;
	}

	FILE *fp1 = fopen("output.txt", "w");
	for (int i = 1; i <= modeNum; i++) {
	}


return 0;
}