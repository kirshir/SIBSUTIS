//1. ������� � ����� ����������� 10x20.
//� ������� �������� ������� 1-� � 2-� ������, 3-� � 4-� ������, �., 9-� � 10-� ������.

#include<stdio.h>

int main(){
	int A[10][20];
	int k = 1;
	for (int j=0; j<10; j++){
		for(int i=0; i<20; i++){
			A[j][i] = k;	
		}
		k++;
	}
	for (int i=1; i<10; i+=2){
		for (int m=0; m<20; m++){
			int temp = A[i][m];
			A[i][m] = A[i - 1][m];
			A[i - 1][m] = temp;
		}
	}
	
	for (int i=0; i<10; i++){
		for (int j=0; j<20; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
