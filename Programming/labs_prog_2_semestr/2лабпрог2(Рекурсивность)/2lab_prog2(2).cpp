//��� ������ ���������  ����� ����� �� N ���������. ��������� ��������, ���������� ������� ��� �������������, 
//� ����� � ��� �������������   ����� ���� ������������������.
//����������� � ����� �������, ������� ���������� ���� ���.

#include <stdio.h>

void NaP(int A[], int n, int i){
	if (n == i){
		return;
	}
	if (A[i] < 0){
		printf("%d ", A[i]);
	} 
	NaP(A, n, i + 1);
	
	if (A[i] > 0){
		printf("%d ", A[i]);
	}
}

int main() {
	int n;
	printf("Massive size: ");
	scanf("%d", &n);
	if (n <= 0) {
		printf("ERROR!");
		return -1;
	}
	int A[n];
	printf("Massive elements(!=0): ");
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	NaP(A, n, 0);
	
	return 0;
}

