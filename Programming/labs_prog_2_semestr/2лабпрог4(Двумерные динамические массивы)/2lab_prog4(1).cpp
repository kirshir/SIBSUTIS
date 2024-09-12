#include <stdio.h>
#include <stdlib.h>
const int n = 5;
typedef int rown[n];

int main() {
	int m;
	printf("Input m: ");
	scanf("%d", &m);
	rown *B;
	rown *C;
	B = new rown[m];
	C = new rown[m];
	if (B == NULL or C == NULL) {
		printf("ERROR!");
		return 1;
	}
	int max = 0;
	int row, col;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = rand() % 100;
			printf("%4d ", B[i][j]);
			if (B[i][j] > max) {
				max = B[i][j];
				row = i;
				col = j;
			}
		}
		printf("\n");
	}
	printf("\n\n");
	
	int c_row = 0, c_col = 0;
    for (int i = 0; i < m; i++) {
        if (i == row) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j == col) {
                continue;
            }
            C[c_row][c_col] = B[i][j];
            c_col++;
        }
        
        c_col = 0;
        c_row++;
    }
	
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			printf("%4d ", C[i][j]);
		}
		printf("\n");
	}
	
	delete B;
	delete C;
	return 0;
}
