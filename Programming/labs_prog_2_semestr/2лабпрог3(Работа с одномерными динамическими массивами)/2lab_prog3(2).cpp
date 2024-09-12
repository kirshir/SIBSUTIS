#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void InsertSort(float* A[], int n){
	for (int i = 1; i < n; i++){
		float* t = A[i];
		int j = i - 1;
		while (j >= 0 && *t < *A[j]){
			A[j + 1] = A[j];
			j = j - 1; 
		}
		A[j + 1] = t;
	}
}

int main(){
	int n;
	printf("Massive size: ");
	scanf("%d", &n);
	float *a = new float[n];	
	float **b = new float*[n];
	if (a == NULL){
		printf("ERROR");
		return 1;
	}
	if (b == NULL){
		printf("ERROR");
		return 1;
	}
	
	srand(time(NULL));
	
	for(int i = 0; i < n; i++){
		a[i] = ((float)rand() / RAND_MAX) * 20 - 10;
		b[i] = &a[i];
	}
	
	InsertSort(b, n);
	printf("original massive:\n");
	for (int i = 0; i < n; i++){
		printf("%f ", a[i]);
	}
	
	printf("\n");
	
	printf("sorted massive: \n");
	for (int i = 0; i < n; i++){
		printf("%f ", *b[i]);
	}
	
	delete[] a;
	delete[] b;
	return 0;
}

