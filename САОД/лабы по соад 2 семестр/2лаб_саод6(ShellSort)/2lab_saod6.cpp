//ShellSort

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
int M = 0;
int C = 0;

void FillInc(int A[], int n){
	for(int i = 0; i < n; i++){
		A[i] = i;
	}
}

void FillDec(int A[],int n){
	for (int i = 0; i < n; i++){
		A[i] = n - i - 1;
	}
}

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

void InsertSort(int A[], int n){
	for (int i = 1; i < n; i++){
		int t = A[i];
		int j = i - 1;
		M++;
		int f = 0;
		while (j >= 0 && t < A[j]){
			C++;
			A[j + 1] = A[j]; M++;
			j = j - 1; 
			f = 1;
		}
		if ( f == 0) {
			C++;
		}
		A[j + 1] = t; M++;
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
			M++;
			int f = 0;
			while (j >= 0 && t < A[j]){
				C++;
				A[j + h[k]] = A[j]; M++;
				j = j - h[k];
				f = 1;
			}
			if (f == 0){
				C++;
			}
			A[j + h[k]] = t; M++;
		}
	}
}


void print(int A[], int n){
	for (int i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
int CheckSum(int A[],int n){
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += A[i];	
	}
	return sum;
}
int RunNumber(int A[], int n){
	int ser = 1;
	for (int i = 0; i < n - 1; i++){
		if (A[i] > A[i + 1]){
			ser += 1;
		}
	}
	return ser;
}


int main(){
	setlocale(LC_ALL, "Russian");
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		printf("N=%d\n\n", n);
		printf("FillInc:\n");
		FillInc(A, n);
//		print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		ShellSort(A, n);
//		print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		M = 0;
		C = 0;
		printf("\n");
		printf("FillDec:\n");
		FillDec(A, n);
//		print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		ShellSort(A, n);
//		print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		printf("\n");
		M = 0;
		C = 0;
		printf("FillRand:\n");
		FillRand(A, n);
//		print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		ShellSort(A, n);
//		print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		printf("\n\n\n\n");
		M = 0;
		C = 0;
	}
	
	printf("N\th1...hm(D.Knut)\t\tInsert(Mô+Cô)\t\tShell(Mô+Cô)\n");
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		int m = log2(n) - 1;
		int h[m - 1];
		Knut(n, h);
		
		FillRand(A, n);
		ShellSort(A, n);
		int Sum_Shell = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		InsertSort(A, n);
		int Sum_Insert = M + C;
		M = 0;
		C = 0;
		
		int h_size = sizeof(h) / sizeof(h[0]);
		char h_str[h_size * 3];
		int offset = 0;
		for (int i = 0; i <= h_size; i++){
			int written = sprintf(h_str + offset, "%d", h[i]);
			offset += written;
			if (i <= h_size - 1){
				h_str[offset++] = ',';
			}
		}
		h_str[offset] = '\0';
		
		printf("%d\t%s\t\t%d\t\t\t%d\n", n, h_str, Sum_Insert, Sum_Shell);
	}
	return 0;
}
