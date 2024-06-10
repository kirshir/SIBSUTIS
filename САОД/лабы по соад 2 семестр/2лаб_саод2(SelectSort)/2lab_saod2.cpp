//SelectSort

#include <stdio.h>
#include <stdlib.h>
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

void SelectSort(int A[], int n){
	for(int i = 0; i < (n - 1); i++){
		int k = i; 
		for (int j = i + 1; j < n; j++){
			C++;
			if (A[j] < A[k]) {
				k = j;
			}
		}
		int temp = A[i]; M++;
		A[i] = A[k]; M++;
		A[k] = temp; M++;
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
	int n = 10;
	int A[n];
	printf("FillInc:\n");
	FillInc(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	SelectSort(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	printf("MOVE = %d\n", M);
	printf("COMPARE = %d\n", C);
	M = 0;
	C = 0;
	printf("\n");
	printf("FillDec:\n");
	FillDec(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	SelectSort(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	printf("MOVE = %d\n", M);
	printf("COMPARE = %d\n", C);
	printf("\n");
	M = 0;
	C = 0;
	printf("FillRand:\n");
	FillRand(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	SelectSort(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	printf("MOVE = %d\n", M);
	printf("COMPARE = %d\n", C);
}


