//сравнение BubbleSort и ShakerSort 

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
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		printf("BubbleSort\n");
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
		
		printf("ShakerSort\n");
		printf("N=%d\n\n", n);
		printf("FillInc:\n");
		FillInc(A, n);
	//	print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		ShakerSort(A, n);
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
		ShakerSort(A, n);
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
		ShakerSort(A, n);
	//	print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		printf("\n\n\n\n");
		M = 0;
		C = 0;
	}
	
	printf("N\tМф + Сф (пузырьковой)\t\t Мф + Сф (шейкерной)\n");
	printf("\tУбыв.    Случ.    Возр.\t\tУбыв.      Случ.      Возр.\n");
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		FillInc(A, n);
		BubbleSort(A, n);
		int Sum_bubble_fact_inc = M + C;
		M = 0;
		C = 0;
		
		FillDec(A, n);
		BubbleSort(A, n);
		int Sum_bubble_fact_dec = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		BubbleSort(A, n);
		int Sum_bubble_fact_rand = M + C;
		M = 0;
		C = 0;
		
		FillInc(A, n);
		ShakerSort(A, n);
		int Sum_shaker_fact_inc = M + C;
		M = 0;
		C = 0;
		
		FillDec(A, n);
		ShakerSort(A, n);
		int Sum_shaker_fact_dec = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		ShakerSort(A, n);
		int Sum_shaker_fact_rand = M + C;
		M = 0;
		C = 0;
		
		printf("%d\t%d    %d    %d", n, Sum_bubble_fact_dec, Sum_bubble_fact_rand, Sum_bubble_fact_inc);
		printf("          %d      %d      %d", Sum_shaker_fact_dec, Sum_shaker_fact_rand, Sum_shaker_fact_inc);
		printf("\n");
	}	
	return 0;
}
