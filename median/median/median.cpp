#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int n = 0, k = 0, smallest = INFINITY, tmp = 0, indexSmallest = NULL;
	int arr[100001];
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%d", &arr[i]);
		//printf("%d ", arr[i]);
	}
	fscanf(fp, "%d", &k);
	fclose(fp);
	for (int i = 1; i <= n-1; i++) {
		indexSmallest = i;
			for (int j = i + 1; j <= n; j++) {
				if (arr[j] < arr[indexSmallest]) {
					indexSmallest = j;
				}
			}
			if (indexSmallest != i) {
				tmp = arr[i];
				arr[i] = arr[indexSmallest];
				arr[indexSmallest] = tmp;
			}
		}
			
		printf("%d \n", arr[k]);
	
	return 0;
}