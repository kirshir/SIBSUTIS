#include <stdio.h>

int main()
{
	int a, b, c, d, e, allsum;
	printf("Input a, b, c, d, e");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	if (a>0) allsum += a;
	if (b>0) allsum += b;
	if (c>0) allsum += c;
	if (d>0) allsum += d;
	if (e>0) allsum += e;
	
	printf("result: allsum=%d", allsum);
	return 0;
}
