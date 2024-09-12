// Даны 3 числа. Поменять  местами большее и меньшее из  этих чисел.
#include <stdio.h>

int main() 
{
	int a, b, c, min, max;
	printf("input a, b, c");
	scanf("%d %d %d", &a, &b, &c);
	
	min = a;
	max = a;
	if (b<min) min = b;
	if (c<min) min = c;
	if (b>max) max = b;
	if (c>max) max = c;
	
	if (a == min) a = max;
	else if (a == max) a = min;
	if (b == min) b = max;
	else if (b == max) b = min;
	if (c == min) c = max;
	else if (c == max) c = min;
	
	printf("result: %d %d %d", a, b, c);
	return 0; 
}
