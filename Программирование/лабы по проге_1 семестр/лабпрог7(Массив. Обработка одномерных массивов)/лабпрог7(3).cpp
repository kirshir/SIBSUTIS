//������������ � ������� ������� ��������� ����� � ��������� [-10,10] ������ �� 20 ��������� ������������� ����.
//������� ��� �� �����.������������ �� ������������� ��������� ������� � ������ �. ������� ������ �

#include <stdio.h>
#include <ctime>
#include <stdlib.h>

const int N=21;
int random(int N) {return rand()% N;} 
int main() {
	float A[20];
	for (int i=0; i<20; i++){
		A[i] = (float)rand()*20/RAND_MAX-10; 
	}
	for (int i=0; i<20; i++) printf("%f ", A[i]);
	
	printf("\n");
	
	float B[20];
	int count = 0;
	for (int i=0; i<20; i++) {
		if (A[i]>0){
			B[count]=A[i];
			count++;
		}
	} 
	for (int i=0; i<count; i++) printf("%f ",B[i]);
	
	return 0;
}
