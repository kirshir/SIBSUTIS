//ShakerSort

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

void ShakerSort(int A[], int n){
	int L = 0;
	int R = n - 1;
	int k = n - 1;
	do {
		for (int j = R; j > L; j--){
			C++;
			if (A[j] < A[j - 1]){
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				k = j;
				M += 3;
			}
		}
		L = k;
		for (int j = L; j < R; j++){
			C++;
			if (A[j] > A[j + 1]){
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				k = j;
				M += 3;
			}
		}
		R = k;
	} while(L < R);
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
	int n = 10;
	int A[n];
	printf("FillInc:\n");
	FillInc(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	ShakerSort(A, n);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	printf("MOVE = %d\n", M);
	printf("COMPARE = %d\n", C);
	M = 0;
	C = 0;
	printf("\n");
	printf("FillDec:\n");
	FillDec(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	ShakerSort(A, n);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	printf("MOVE = %d\n", M);
	printf("COMPARE = %d\n", C);
	M = 0;
	C = 0;
	printf("\n");
	printf("FillRand:\n");
	FillRand(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	ShakerSort(A, n);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	printf("MOVE = %d\n", M);
	printf("COMPARE = %d\n", C);
	printf("\n\n\n\n");	
	return 0;
}





















































