// Двоичный поиск 

#include <stdio.h>
#include <stdlib.h>
int C = 0;

void FillInc(int A[], int n){
	for(int i = 0; i < n; i++){
		A[i] = i;
	}
}

void print(int A[], int n){
	for (int i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}


int First_version(int A[], int n, int X) {
	int L = 0, R = n - 1; 
	while(L <= R){
		int m = (L + R )/ 2;
		C++;
		if (A[m] == X) {
			return m;
		}
		C++;
		if (A[m] < X) {
			L = m + 1;
		}
		else {
			R = m - 1;
		}
	}
	return -1;
}

int Second_version(int A[], int n, int X){
	int L = 0, R = n - 1;
	while(L < R){
		int m = (L + R )/ 2;
		C++;
		if (A[m] < X){
			L = m + 1;
		}

		else R = m;
	}
	C++;
	if (A[R] == X) {
		return R;
	}
	else return -1;
}


int main() {
	int n = 10;
	int A[n];
	//int A[n] = {1, 1, 1, 1, 3, 4, 5, 6, 7, 8};
	int X;
	printf("Need to find = ");
	scanf("%d", &X);
	
	FillInc(A, n);
	print(A, n);
	int m = First_version(A, n, X);
	if (m != -1){
		printf("Element at number = %d\n", m);
		printf("C = %d\n", C);
	}
	else printf("Element not found\n");
	C = 0;
	
	print(A, n);
	m = Second_version(A, n, X);
	if (m != -1){
		printf("Element at number = %d\n", m);
		printf("C = %d", C);
	}
	else printf("Element not found\n");
	return 0;

}
