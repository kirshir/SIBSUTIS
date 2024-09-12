#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void FillRand(int A[],int n){
	for(int i = 0; i < n; i++){
		A[i] = rand()%(2*n);
	}
}

void Knut(int n, int *h){
	int m = log2(n) - 1;
	h[0] = 1;
	for (int i = 1; i < m; i++){
		h[i] = 2 * h[i - 1] + 1;
	}	
}

void ShellSort(int A[], int n) {
	int m = log2(n) - 1;
	int h[m - 1];
	Knut(n, h);
	for (int k = m - 1; k >= 0; k--) {
		for (int i = h[k]; i < n; i++){
			int t = A[i];
			int j = i - h[k];
			while (j >= 0 && t > A[j]){
				A[j + h[k]] = A[j];
				j = j - h[k];
			}
			A[j + h[k]] = t; 
		}
	}
}

int regular_search(int A[], int N, int X, int *C){
	for (int i = 0; i < N; i++){
		(*C)++;
		if (A[i] == X){
			return i;
		}
		else continue;
	}
	return -1;
}

int binary_search(int A[], int N, int X, int *C){
	int L = 0, R = N - 1;
	while(L < R){
		int m = (L + R )/ 2;
		(*C)++;
		if (A[m] > X){
			L = m + 1;
		}
		else R = m;
	}
	(*C)++;
	if (A[R] == X) {
		return R;
	}
	else return -1;
}


int main() {
	int X;
	printf("Need to find = ");
	scanf("%d", &X);	
	for (int i = 100; i <= 1000; i += 900){
		int N = i;
		int A[N];
		FillRand(A, N);
		ShellSort(A, N);
		int C = 0, C1 = 0;
		int m = binary_search(A, N, X, &C);
		int m1 = regular_search(A, N, X, &C1);
		printf("N = %d\n", N);
		if (m != -1 || m1 != -1) {
			printf("Binary Search : Element %d, at number  = %d\tC = %d\n", X, m, C);
			printf("Regular Search : Element %d, at number  = %d\tC = %d\n", X, m1, C1);
		}
		else printf("Element not found\n");
		printf("\n");
	}
	return 0;
}
