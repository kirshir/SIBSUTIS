//Ќайти и вывести простые числа и  их количество в диапазоне от 2 до n, n ввести с клавиатуры.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, count=0, i, m=2;
	printf("input n\n");
	scanf("%d", &n);
	
	do {
		for (i=2; i<m; i++) {
			if (m % i == 0)
				break;
		
			else {
				printf("%d\n", m);
				count += 1;
				break;
			}
		}
	m++;
	} while (m<=n);
	printf("count=%d", count);
	return 0;
}

