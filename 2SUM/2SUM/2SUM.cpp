#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int k = 0, n = 0, element[10001], twoSum[2],check = 0;
	FILE *fp = fopen("input.txt", "r");
	FILE *fd = fopen("output.txt", "w");
	if (fp == NULL)
		return -1;
	fscanf(fp, "%d %d", &k, &n);
	
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			fscanf(fp, "%d", &element[j]);	// scan the array elements for each line
		}
		for (int j = 1; j < n; j++) {
			for (int l = j+1; l <= n; l++) {
				if (element[j]+element[l] == 0) {
					twoSum[0] = j;
					twoSum[1] = l;
					check = 1;
				}
			}
		}
		if (check != 1) {
			fprintf(fd, "-1 \n");
			check = 0;
		}
		else {
			fprintf(fd, "%d %d \n", twoSum[0],twoSum[1]);
			check = 0;
		}
	}
	fclose(fp);
	fclose(fd);
	return 0;
}