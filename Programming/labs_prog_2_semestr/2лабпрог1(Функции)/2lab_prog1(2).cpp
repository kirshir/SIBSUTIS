//�������� ������� ���������� � ������� y=x^n, ��� n � ����� ������������� ��� ������������� �����; 
//x �  ������������ �����. ������������ ����.
#include <stdio.h>

float Function(int n, float x){
	double y = 1.0;
	if (n >= 0){
		for (int i = 0; i < n; i++){
			y *= x;
		}
	}
	if (n < 0){
		for (int i = 0; i > n; i--){
			y /= x;
		}
	}
	return y;
}

int main(){
	float x;
	printf("x:");
	scanf("%f", &x);	
	int n;
	printf("n:");
	scanf("%d", &n);
	double y = Function(n, x);
	printf("y = %lf", y);
	return 0;
}
