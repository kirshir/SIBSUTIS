#include <stdio.h>
#include <stdlib.h>

void BetweenMin(int A[], int size){
	int min = A[0], min1 = A[1];
	int min_index, min1_index;
	for (int i = 1; i < size; i++){
		if (A[i] < min){
			min1 = min;
			min = A[i];
			min_index = i;
		}
		else if(A[i] < min1 && A[i] != min){
			min1 = A[i];
			min1_index = i;
		}
	}
	for (int i = min_index + 1; i < min1_index; i++){
		A[i] = 0;
	}
} 


int main() {
	int size = 15;
	int A[size];
	for (int i = 0; i < size; i++){
		A[i] = rand() % 100;
	}
	for (int i = 0; i < size; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	BetweenMin(A, size);
	for (int i = 0; i < size; i++){
		printf("%d ", A[i]);
	}
	return 0;
}
