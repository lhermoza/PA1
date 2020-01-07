#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void print(int** square, int rows,int columns);

int main(int argc, char** argv) {
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("error\n");
		return 0;
	}
	int rows1 = 0; int columns1 = 0; int num = 0;
	fscanf(fp, "%d", &rows1);
	fscanf(fp, "%d", &columns1);

	int** square = (int**) malloc(sizeof(int*) * rows1);
	for (int i = 0; i < rows1; i++) {
		square[i] = (int*) malloc(sizeof(int) * columns1);
	}
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns1; j++) {
			fscanf(fp, "%d", &num);
			square[i][j] = num;
		}
	}
	int rows2 = 0; int columns2; int num2 = 0;
	fscanf(fp, "%d", &rows2);
	fscanf(fp, "%d", &columns2);

	int** square2 = (int**) malloc(sizeof(int*) * rows2);
	for (int i = 0; i < rows2; i++) {
		square2[i] = (int*) malloc(sizeof(int) * columns2);
	}
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < columns2; j++) {
			fscanf(fp, "%d", &num2);
			square2[i][j] = num2;
		}
	}
	if (columns1 != rows2) {
		printf("bad-matrices\n");
		return 0;
	}
	int ans = 0;
	int** answer = (int**) malloc(sizeof(int*) * rows1);
	for (int i = 0; i < rows1; i++) {
		answer[i] = (int*) malloc(sizeof(int) * columns2);
	}
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns2; j++) {
			for (int k = 0; k < rows2; k++) {
				ans += square[i][k] * square2[k][j];
			}
			answer[i][j] = ans;
			ans = 0;
		}
	}
	print(answer, rows1, columns2);
	fclose(fp);
	return 0;
}

void print(int** square, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%d\t", square[i][j]);
		}
		printf("\n");
	}
	return;
}
