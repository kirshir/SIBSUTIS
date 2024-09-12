//Сформировать с помощью датчика случайных чисел в диапазоне [0,10] массив из 15 элементов целого типа.
//Вывести его на экран. Вывести элементы массива, исключая ранее встречавшиеся.

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
