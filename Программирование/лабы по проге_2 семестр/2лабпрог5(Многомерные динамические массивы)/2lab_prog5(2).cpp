#include <stdio.h>
#include <stdlib.h>

int main() {
	int **A = (int**) malloc(10 * sizeof(int*));
    for (int i = 0; i < 10; i++) {
        A[i] = (int*) malloc((i + 1 )* sizeof(int));
    }
	
	for (int i = 1; i < 10; i++) {
    	for (int j = 1; j <= i; j++) {
			A[i][j] = i * j;
		}
	}
	
	for(int i = 1; i < 10; i++) {
    	for(int j = 1; j <= i; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
	for (int i = 0; i < 10; i++) {
		delete A[i]; 
        A[i] = NULL;
    }
	delete  A; 
	A = NULL;
  

	return 0;
}
