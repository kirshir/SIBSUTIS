//Даны 4 числа. Определить порядковый номер  наименьшего  среди них

#include <stdio.h>

int main()
{
	int a, b, c, d, min;
	printf("input a, b, c, d");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if (a<b && a<c && a<d) {
		min = a;
		printf("1 number min");
	}
	else if (b<a && b<c && b<d) {
		min = b;
		printf("2 number min");
	}
	else if (c<a && c<b && c<d){
		min = c;
		printf("3 number min");
	} 
	else {
		min = d;
		printf("4 number min");
	}
	printf("=%d", min);
	return 0;  
}
