//ƒаны четыре числа. Ќайти разность между наибольшим и наименьшим среди них.
#include <stdio.h>

int main()
{
	int a, b, c, d, min, max, diff;
	printf("input a,b,c,d");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	min = a;
	if (b<min) min = b;
	if (c<min) min = c;
	if (d<min) min = d;
	
	max = a;
	if (b>max) max = b;
	if (c>max) max = c;
	if (d>max) max = d;
	
	diff = max - min;
	printf("result: %d", diff);
	return 0;
	
}
