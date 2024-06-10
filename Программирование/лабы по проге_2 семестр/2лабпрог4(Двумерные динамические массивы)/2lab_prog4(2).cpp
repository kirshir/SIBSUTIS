#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n;
	printf("Input m: ");
	scanf("%d", &m);
	printf("Input n: ");
	scanf("%d", &n);

	int **A = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		A[i][j] = rand() % 20;
		}
	}
    
    int **D = (int**) malloc((m + 1) * sizeof(int*));
    for (int i = 0; i < m + 1; i++) {
        D[i] = (int*)malloc((n + 1) * sizeof(int));
    }
	for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		D[i][j] = A[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int sumrow = 0;
		for (int j = 0; j < n; j++) {
			sumrow += A[i][j];
		}
		D[i][n] = sumrow;
	}
	
	for (int j = 0; j < n; j++) {
		int sumcol = 0;
		for (int i = 0; i < m; i++) {
			sumcol += A[i][j];
		}
		D[m][j] = sumcol;
	}

	int Sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            Sum += A[i][j];
        }
    }
    D[m][n] = Sum;
	
	for(int i = 0; i < m + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
	
	free (A);
	free (D);
	return 0;
}
