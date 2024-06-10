//Сформировать из случайных чисел матрицу 3х3 - магический квадрат, т.е. такой, в котором суммы элементов во
//всех строках и столбцах одинаковы. (алгоритм подбора, матрица генерируется до тех пор, 
//пока не получиться магический квадрат). Подсчитать количество генераций.

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

bool Magic_or_no(int A[3][3]){
	int sum = 0;
	for (int j = 0; j < 3; j++){
		sum += A[0][j]; 
	}
	for (int i = 0; i < 3; i++){
		int linesum = 0;
		for (int j = 0; j < 3; j++){
			linesum += A[i][j]; 
		}
		if (linesum != sum) {return false;} 
	}
	for (int j = 0; j < 3; j++) {
		int colsum = 0;
		for (int i = 0; i < 3; i++) {
			colsum += A[i][j]; 
		}
		if (colsum != sum) {return false;} 
	}
	return true;	
}

int main() {
	int A[3][3];
	int count = 0;
	srand(time(0));
	do {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++){
				A[i][j] = rand() % 10;
			} 
		}
		count++;
	} while (!Magic_or_no(A));

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf("%d ", A[i][j]); 
		}
		printf("\n"); 
	}
	printf("%d", count);
	return 0;
}
