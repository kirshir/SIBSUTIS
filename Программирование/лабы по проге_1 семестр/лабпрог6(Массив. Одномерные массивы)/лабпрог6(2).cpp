//��� �������� i=1, 2,..,n ��������� ����� ��������� �� n ��
//i � ������� ���������� � ������  �={�1,�2,..,�n}, ���������
//Ci= n!/(i!(n - i)!).  ����� n>0 ������ � ����������. ���������� ������ ������� �� �����.

#include <stdio.h>

int main(){
	int n, i;
	printf("Input n\n");
	scanf("%d",&n);
	int C[n];
	int fact1=1,forf1;
	for (int forf1=1;forf1<=n;forf1++) {
		fact1*=forf1;}
		
	
	for (i=1;i<=n;i++) {
		int fact2=1,forf2;
		int fact3=1,forf3;
		for (forf2=1; forf2<=i; forf2++) fact2*=forf2;
		for (forf3=1; forf3<=(n-i);forf3++) fact3*=forf3;
		C[i] = fact1/(fact2*fact3);
		printf("C[%d]=%d\n", i, C[i]);
	}
	return 0;
}
