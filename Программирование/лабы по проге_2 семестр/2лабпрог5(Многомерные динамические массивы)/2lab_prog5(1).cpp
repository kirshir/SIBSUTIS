#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, k;
	printf("Input m: ");
	scanf("%d", &m);
	
	int *A = (int*) malloc(m * sizeof(int));
	if (A == NULL) {
		printf("ERROR!");
		return 1;
	}
	
	for (int i = 0; i < m; i++) {
		A[i] = rand() % 100;
		printf("%d ", A[i]);	
	}
	printf("\n");
	printf("Input k(k<m): ");
	scanf("%d", &k);
	
	if (k >= m) {
        printf("Invalid input for k");
        free(A);
        return 1;
    }
	
	int rows = m / k + (m % k); 
	
	int **B = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        B[i] = (int*) malloc(k * sizeof(int)); 
        for (int j = 0; j < k; j++) { 
        	if (i * k + j < m) {
        		B[i][j] = A[i * k + j];
			}
			else {
				B[i][j] = 0;
			}
		}
    }
    
	for(int i = 0; i < rows; i++) {
    	for(int j = 0; j < k; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
	}
	
	free(A);
    for (int i = 0; i < rows; i++) {
        free(B[i]);
    }
	free (B);
	return 0;
}
