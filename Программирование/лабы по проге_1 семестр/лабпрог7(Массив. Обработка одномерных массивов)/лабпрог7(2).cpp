//������������ � ������� ������� ��������� ����� � ��������� [0,10] ������ �� 15 ��������� ������ ����.
//������� ��� �� �����. ������� �������� �������, �������� ����� �������������.

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main() {
	int A[15];
	bool visited[15] = {false};
	
	srand(time(NULL));
	for (int i=0; i<15; i++){
		A[i] = rand() % 11;
	}
	for (int i=0; i<15; i++) printf("%d ", A[i]);
	
	printf("\n");
	
	for (int i=0; i<15; i++){
		if (!visited[A[i]]) {
			printf("%d ", A[i]);
			visited[A[i]] = true;
		}	
	}

	return 0;
}
