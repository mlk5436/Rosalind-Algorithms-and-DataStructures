#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int findCandidate(int a[], int size);
int main() {
	int lines = 0, elements = 0, c = 0;
	int element[10001], modes[10001];
	FILE *fp = fopen("input.txt", "r");	// get input from textfile to fp pointer
	if (fp == NULL)						// if the pointer point to nothing return
		return 0;
	fscanf(fp, "%d %d", &lines, &elements);	// scan the number of lines and elements for each line
	for (int i = 0; i <= elements; i++) {	// initialize all elements to 0
		element[i] = 0;
	}
	for (int i = 1; i <= lines; i++) {	// iterate lines
		for (int i = 1; i <= elements; i++) {	// iterate elements
			fscanf(fp, "%d", &element[i]);		// scan each elements in line i to element array
		}
		c++;
		modes[c] = findCandidate(element, elements);
	}
	fclose(fp);
	FILE *fd = fopen("output.txt", "w");
	for (int i = 1; i <= lines; i++) {
		fprintf(fd, "%d ", modes[i]);
	}
	fclose(fd);
	
	return 0;

}

int findCandidate(int a[], int size) {
	int  maj_index = 1, count = 1;
	for (int j = 2; j <= size; j++) {
		if (a[maj_index] == a[j])
			count++;
		else
			count--;
		if (count == 0) {
			maj_index = j;
			count = 1;
		}
	}
	
	int k = 0;
	for (int i = 1; i <= size; i++) {
		if (a[i] == a[maj_index])
			k++;
	}
	if (k > size / 2)
		return a[maj_index];
	else return -1;
	
}