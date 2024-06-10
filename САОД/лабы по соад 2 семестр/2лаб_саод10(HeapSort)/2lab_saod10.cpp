#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

void Heapify(int L, int R, int A[]){
	M++;
	int x = A[L];
	int i = L;
	while (true){
		int j = 2 * i;
		if (j > R) break;
		C++;
		if (j < R && A[j + 1] <= A[j]) {
			j += 1;
		}
		C++;
		if (x <= A[j]) break;
		A[i] = A[j];
		M++;
		i = j;
	}
	M++;
	A[i] = x;
}

void HeapSort(int A[], int n) {
	int L = n / 2 - 1;
	while (L >= 0) {
		Heapify(L, n - 1, A);
		L -= 1;
	}
	int R = n - 1;
	while (R > 0){
		int temp = A[0];
		A[0] = A[R];
		A[R] = temp;
		M += 3;
		R -= 1;
		Heapify(0, R, A);
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

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 10;
	int A[n];
	
	FillInc(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	HeapSort(A, n);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	
	FillDec(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	HeapSort(A, n);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	
	FillRand(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	HeapSort(A, n);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));	
	printf("   Трудоемкость построения пирамиды\n");
    printf("N\tM+C\t\t    Мфакт+Сфакт\t\n");
    printf("\tтеоретич.\tУбыв.\tСлуч.\tВозр.\n");
	for (int i = 100; i <= 500; i += 100){
		int n = i;
		int A[n];
		int L = 1;
		int R = n - 1;
		int Ct_Mt = 2 * log2(R / L) + log2(R / L) + 2;
		FillInc(A, n);
		Heapify(L, R, A);
		int Sum_Inc = M + C;
		M = 0;
		C = 0;
		
		FillDec(A, n);
		Heapify(L, R, A);
		int Sum_Dec = M + C;
		M = 0;
		C = 0;
		
		FillRand(A, n);
		Heapify(L, R, A);
		int Sum_Rand = M + C;
		M = 0;
		C = 0;
		printf("%d\t %d\t\t%d\t %d\t %d\n", n, Ct_Mt, Sum_Dec, Sum_Rand, Sum_Inc);
	}
	printf("\n   Трудоемкость пирамидальной сортировки\n");
    printf("N\tM+C\t\t(HeapSort)Мфакт+Сфакт\t\n");
    printf("\tтеоретич.\tУбыв.\tСлуч.\tВозр.\n");
	for (int i = 100; i <= 500; i += 100) {
	int n = i;
	int A[n];
	int L = 1;
	int R = n - 1;
	int T = 2 * n * log2(n) + n + 2 + n * log2(n) + 6.5 * n - 4;
	
    FillDec(A, n);
    HeapSort(A, n);
    int T1 = M + C;
    M = 0;
    C = 0;
    
    FillRand(A, n);
    HeapSort(A, n);
    int T2 = M + C;
    M = 0;
    C = 0;
    
    FillInc(A, n);
    HeapSort(A, n);
    int T3 = M + C;
    M = 0;
    C = 0;
    
    printf("%d\t%d\t\t%d\t%d\t%d\n", n, T, T1, T2, T3);
	}
	return 0;
}
