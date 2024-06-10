#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int M = 0;
int C = 0;
int max_rek = 0;

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

void QuickSort1(int L, int R, int A[], int rek = 0) {
	max_rek = max(max_rek, rek);
	M++;
	int x = A[L];
	int i = L;
	int j = R;
	while (i <= j) {
		while (A[i] < x) {
			C++;
			i++;
		}
		while (A[j] > x) {
			C++;
			j--;
		}
		if (i <= j) {
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			M += 3;
			i++;
			j--;
		}
	}
	C++;
	if (L < j) {
		QuickSort1(L, j , A, rek + 1);
	}
	C++;
	if (i < R) {
		QuickSort1(i, R, A, rek + 1);
	}
}

void QuickSort2(int L, int R, int A[], int rek = 0) {
	max_rek = max(max_rek, rek);
	while (L < R) {
		int x = A[L];
		int i = L;
		int j = R;
		while(i <= j) {
			while (A[i] < x) {
				i++;
			}
			while (A[j] > x) {
				j--;
			}
			if (i <= j) {
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i++;
				j--;
	 		}
		}
		
		if ((j - L) < (R - i)) {
			QuickSort2(L, j, A, rek + 1);
			L = i;
		}
		else {
			QuickSort2(i, R, A, rek + 1);
			R = j;
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

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 10;
	int A[n];
	int L = 0;
	int R = n - 1;
	
    printf("FILLINC:");
    FillInc(A, n);
    print(A, n);
    printf("Sum Before Sort=%d\n", CheckSum(A, n));
    printf("Ser Before Sort=%d\n", RunNumber(A, n));
    QuickSort1(L, R, A);
    print(A, n);
    printf("Sum After Sort=%d\n", CheckSum(A, n));
    printf("Ser After Sort=%d\n", RunNumber(A, n));
    printf("Move= %d\n", M);
    printf("Compare= %d\n\n", C);
    
	M = 0;
	C = 0;
	printf("FILLDEC:");
	FillDec(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	QuickSort1(L, R, A);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	printf("Move= %d\n", M);
	printf("Compare= %d\n\n", C);
	
	M = 0;  
	C = 0;
	printf("FILLRAND:");
	FillRand(A, n);
	print(A, n);
	printf("Sum Before Sort=%d\n", CheckSum(A, n));
	printf("Ser Before Sort=%d\n", RunNumber(A, n));
	QuickSort1(L, R, A);
	print(A, n);
	printf("Sum After Sort=%d\n", CheckSum(A, n));
	printf("Ser After Sort=%d\n", RunNumber(A, n));
	printf("Move= %d\n", M);
	printf("Compare= %d\n\n", C);
  	
	printf("   Трудоемкость метода Хоара\n");
	printf("\t\QuickSort(Мфакт+Сфакт)\t\n");
  	printf("N\tУбыв.\tСлуч.\tВозр.\n");
	for (int i = 100; i <= 500; i += 100) {
   		int n = i;
   		int A[n];
	    int L = 0;
	    int R = n - 1;
	    
	    M = 0;
	    C = 0;
	    FillDec(A, n);
	    QuickSort1(L, R, A);
	    int T1 = M + C;
	    M = 0;
	    C = 0;
	    
	    FillRand(A, n);
	    QuickSort1(L, R, A);
	    int T2 = M + C;
	    M = 0;
	    C = 0;
	    
	    FillInc(A, n);
	    QuickSort1(L, R, A);
	    int T3 = M + C;
	    M = 0;
	    C = 0;
	    
	    printf("%d\t%d\t%d\t%d\n", n, T1, T2, T3);
  	}
  	printf("\n  Глубина рекурсии сортировки методом Хаора\n");
  	printf("N\t\tQuickSort1\t    QuickSort2\n");
  	printf("\tУбыв   Случ     Возр     Убыв   Случ   Возр\n");
	for (int i = 100; i <= 500; i += 100) {
		int n = i;
		int A[n];
		int L = 0;
	    int R = n - 1;
	    max_rek = 0;
		
		FillDec(A, n);
	    QuickSort1(L, R, A);
	    int rek_1_dec = max_rek;
		max_rek = 0;
		
		FillRand(A, n);
	    QuickSort1(L, R, A);
	    int rek_1_rand = max_rek;
		max_rek = 0;
		
		FillInc(A, n);
	    QuickSort1(L, R, A);
	    int rek_1_inc = max_rek;
		max_rek = 0;
		
		FillDec(A, n);
	    QuickSort2(L, R, A);
	    int rek_2_dec = max_rek;
		max_rek = 0;
		
		FillRand(A, n);
	    QuickSort2(L, R, A);
	    int rek_2_rand = max_rek;
		max_rek = 0;
		
		FillInc(A, n);
	    QuickSort2(L, R, A);
	    int rek_2_inc = max_rek;
	    
	    printf("%d\t%d\t%d\t%d\t  %d\t %d\t%d\n", n, rek_1_dec, rek_1_rand, rek_1_inc, 
												rek_2_dec, rek_2_rand, rek_2_inc);
	}
	return 0;
}
