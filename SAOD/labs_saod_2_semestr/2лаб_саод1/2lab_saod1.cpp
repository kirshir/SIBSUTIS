#include <stdio.h>
#include <stdlib.h>
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
	FillInc(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	FillDec(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
	FillRand(A, n);
	print(A, n);
	printf("%d\n", CheckSum(A, n));
	printf("%d\n", RunNumber(A, n));
}


