#include <stdio.h>
#include <stdlib.h>

int divideAndConquer(int arr[], int size, int num);

int main(){

	int n = 0, m = 0;
	int El[200000];
	int num[20000];
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL){
		printf("Fail to open text file!\n");
		return 0;
	}
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);
	for (int i = 1; i <= n; i++){
		fscanf(fp, "%d ", &El[i]);
	}
	for (int i = 1; i <= m; i++){
		fscanf(fp, "%d ", &num[i]);
	}
	
	fclose(fp);


	printf("n: %d, m: %d\n", n, m);

	for (int i = 1; i <= m; i++){
		//printf("%d ", arr[i]);
		int p = divideAndConquer(El, n, num[i]);
		printf("%d ", p);
	}
	printf("\n");
	

	return 0;
}

int divideAndConquer(int El[], int size, int num){
	// if the size of array is 0, exite
	int arr[20000];
	if (num == El[size / 2]){ 
		return size / 2;
	}
	else if (num > El[size / 2]){ 
		for (int i = 1; i <= size / 2; i++){
			arr[i] = El[(size / 2) + 1 + i];
		}
		return divideAndConquer(arr, size / 4, num);
	}
	else if (num < El[size/2]){
		for (int i = 1; i <= (size/2)-1; i++){
			arr[i] = El[i];
		}
		return divideAndConquer(arr, size / 4, num);
	}
	else{
		return -1;
	}
}