// BubbleSort

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

void BubbleSort(int A[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j >= i + 1; j--){
			C++;
			if (A[j] < A[j - 1]){
				int temp = A[j]; 
				A[j] = A[j - 1]; 
				A[j - 1] = temp;
				M += 3;
			}
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
	//	print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		BubbleSort(A, n);
	//	print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		M = 0;
		C = 0;
		printf("\n");
		printf("FillDec:\n");
		FillDec(A, n);
	//	print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		BubbleSort(A, n);
	//	print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		printf("\n");
		M = 0;
		C = 0;
		printf("FillRand:\n");
		FillRand(A, n);
	//	print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		BubbleSort(A, n);
	//	print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		printf("\n\n\n\n");
		M = 0;
		C = 0;
	}
	printf("N\tM+C(теор)\t  М(факт)+С(факт)\n");
	printf("\t\t\tУбыв.\tСлуч.\tВозр.\n");
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		FillInc(A, n);
		BubbleSort(A, n);
		int C_teor = (pow(n, 2) - n) / 2;
		int M_teor = (3 * (pow(n, 2) - n)) / 4;
		int Sum_teor = C_teor + M_teor;
		int Sum_fact_inc = M + C;
		M = 0;
		C = 0;
		
		FillDec(A, n);
		BubbleSort(A, n);
		int Sum_fact_dec = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		BubbleSort(A, n);
		int Sum_fact_rand = M + C;
		M = 0;
		C = 0;
		printf("%d\t%d\t\t%d\t%d\t%d\n", n, Sum_teor, Sum_fact_dec, Sum_fact_rand, Sum_fact_inc); 
	}	
	return 0;
}
