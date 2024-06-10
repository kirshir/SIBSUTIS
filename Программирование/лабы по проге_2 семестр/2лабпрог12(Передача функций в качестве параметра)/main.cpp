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
 
 	printf("Количество элементов массива: %d\n", n);
 	printf("Затраченное время Select Sort целые числа: %lf секунд\n", time1);
 	printf("Затраченное время Select Sort вещественные числа: %lf секунд\n", time2);
    printf("Затраченное время Insert Sort целые числа: %lf секунд\n", time3);
	printf("Затраченное время Insert Sort вещественные числа: %lf секунд\n", time4);
	printf("Затраченное время Bubble Sort целые числа: %lf секунд\n", time5);
	printf("Затраченное время Bubble Sort вещественные числа: %lf секунд\n", time6);
	return 0;
}

