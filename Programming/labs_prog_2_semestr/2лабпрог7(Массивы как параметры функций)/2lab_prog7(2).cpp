#include <stdio.h>
#include <stdlib.h>

int sum(int *row, int row_len, int *suma){
	for (int j = 1; j <= row[0]; j++){
		*suma += row[j];
	}
}


int main(){
	int col_len = 7;
	int **A = (int **)malloc(col_len * sizeof(int*));
	for (int i = 0; i < col_len; i++){
		int row_len = rand() % 8 + 2;
		A[i] = (int*)malloc((row_len + 1) * sizeof(int));
		A[i][0] = row_len;
		for (int j = 1; j <= row_len; j++){
			A[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < col_len; i++){
		int suma = 0;
		sum(A[i], A[i][0], &suma);
		for (int j = 0; j <= A[i][0]; j++){
			printf("%d ", A[i][j]);
		}
		printf("  %d\n", suma);
	}
	for (int i = 0; i < col_len; i++) {
        free(A[i]);
    }
    free(A);
	return 0;
}
