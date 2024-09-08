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

int main(){
	int X;
	printf("Need to find = ");
	scanf("%d", &X);
	printf("N\tC(1 version)\tC(2 version)\n");
	for (int i = 100; i <= 1000; i += 100){
		int n = i;
		int A[n];
		FillInc(A, n);
		int m = First_version(A, n, X);
		int C1 = C;
		C = 0;
		int m1 = Second_version(A, n, X);
		int C2 = C;
		if (m != -1 && m1 != -1){
			printf("%d\t\t%d\t\t%d\n", n, C1, C2);
		}
		else printf("%d\t    Element not found\n", n);
		C = 0;
	}
	return 0;
}
