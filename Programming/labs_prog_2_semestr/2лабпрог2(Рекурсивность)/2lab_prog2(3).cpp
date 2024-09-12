//Написать рекурсивную функцию для перевода числа из десятичной системы счисления в двоичную.

#include <stdio.h>

int Converting(int N){
	if (N != 0) {
		int a = N % 2;
		N = N / 2;
		Converting(N);
		printf("%d", a);
	}
}

int main() {
	int N;
	printf("Choose Number: ");
	scanf("%d", &N);
	
	Converting(N);
	return 0;
}
