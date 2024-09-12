#include "function.h"
#include <locale.h>
#include <stdio.h>

int main() {
 	setlocale(LC_ALL, "Russian");
    int n = 50000;
    int A[n];
    float B[n];
    int L = 0;
    int R = n - 1;

    FillRandInt(A, n);
    FillRandFloat(B, n);
    double time1 = timer(SelectSort, A, n);
    double time2 = timer2(SelectSort2, B, n);

    FillRandInt(A, n);
    FillRandFloat(B, n);
    double time3 = timer(InsertSort, A, n);
    double time4 = timer2(InsertSort2, B, n);

    FillRandInt(A, n);
    FillRandFloat(B, n);
    double time5 = timer(BubbleSort, A, n);
 	double time6 = timer2(BubbleSort2, B, n);
 
 	printf("���������� ��������� �������: %d\n", n);
 	printf("����������� ����� Select Sort ����� �����: %lf ������\n", time1);
 	printf("����������� ����� Select Sort ������������ �����: %lf ������\n", time2);
    printf("����������� ����� Insert Sort ����� �����: %lf ������\n", time3);
	printf("����������� ����� Insert Sort ������������ �����: %lf ������\n", time4);
	printf("����������� ����� Bubble Sort ����� �����: %lf ������\n", time5);
	printf("����������� ����� Bubble Sort ������������ �����: %lf ������\n", time6);
	return 0;
}

