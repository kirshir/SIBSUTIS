#include <stdio.h>

int main()
{
	int a, b, c, d, e, f, g, h, pos = 0, neg = 0; 
	printf("input a, b, c, d, e, f, g, h");
	scanf(" %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
	
	if (a>0) pos += 1;
	else neg += 1;
	if (b>0) pos += 1;
	else neg += 1;
	if (c>0) pos += 1;
	else neg += 1;
	if (d>0) pos += 1;
	else neg += 1;
	if (e>0) pos += 1;
	else neg += 1;
	if (f>0) pos += 1;
	else neg += 1;
	if (g>0) pos += 1;
	else neg += 1;
	if (h>0) pos += 1;
	else neg += 1;
	
	printf("result: positive=%d negative=%d", pos, neg);
	return 0;
}
