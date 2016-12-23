#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(){

	int num = 0;
	FILE *fp;
	fp = fopen("fibnum.txt", "r");
	if (fp == NULL){
		return -1;
	}
	
	fscanf(fp, "%d", &num);
	
	printf("n = %d, fib = %d\n", num, fib(num));

	fclose(fp);

	return 0;
}

int fib(int n){
	int fib[25];
	fib[0] = 0;
	fib[1] = 1;

	if (n == 0)
		return fib[0];
	
	if (n == 1)
		return fib[1];

	for (int i = 2; i <= n;i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}