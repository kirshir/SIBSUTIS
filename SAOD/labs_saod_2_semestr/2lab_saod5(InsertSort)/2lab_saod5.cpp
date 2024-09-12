//InsertSort

#include <stdio.h>
#include <stdlib.h>
#include <string>
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
		InsertSort(A, n);
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
	//  print(A, n);
		printf("Sum Before Sort=%d\n", CheckSum(A, n));
		printf("Ser Before Sort=%d\n", RunNumber(A, n));
		InsertSort(A, n);
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
		InsertSort(A, n);
	//	print(A, n);
		printf("Sum After Sort=%d\n", CheckSum(A, n));
		printf("Ser After Sort=%d\n", RunNumber(A, n));
		printf("MOVE = %d\n", M);
		printf("COMPARE = %d\n", C);
		printf("\n\n\n\n");
		M = 0;
		C = 0;
	}
	printf("Трудоемкость метода прямого включения InsertSort\n");
	printf("N\tM+C\t\t    Мфакт+Сфакт\t\n");
	printf("\tтеоретич.\tУбыв.\tСлуч.\tВозр.\n");
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		int T = (((n * n) - n) / 2) + (((n * n - n) / 2) + 2 * n - 2);
		FillInc(A, n);
		InsertSort(A, n);
		int Sum_insert_fact_inc = M + C;
		M = 0;
		C = 0;
		
		FillDec(A, n);
		InsertSort(A, n);
		int Sum_insert_fact_dec = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		InsertSort(A, n);
		int Sum_insert_fact_rand = M + C;
		M = 0;
		C = 0;
		printf("%d\t%d\t\t%d\t%d\t%d\n", n, T, Sum_insert_fact_dec, Sum_insert_fact_rand, Sum_insert_fact_inc);
	}
	
	printf("\n\nТрудоемкость квадратичных методов сортировки\n");
  	printf("N\t\t\tM+C\n");
  	printf("\tSelect\tBubble\tShaker\tInsert\n");
	for (int i = 100; i <= 500; i+= 100){
		int n = i;
		int A[n];
		FillRand(A, n);
		SelectSort(A, n);
		int Sum_Select = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		BubbleSort(A, n);
		int Sum_Bubble = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		ShakerSort(A, n);
		int Sum_Shaker = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		InsertSort(A, n);
		int Sum_Insert = M + C;
		M = 0;
		C = 0;
		printf("%d\t%d\t%d\t%d\t%d\n", n, Sum_Select, Sum_Bubble, Sum_Shaker, Sum_Insert);
	}	
	return 0;
}
