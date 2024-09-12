#include <stdio.h>

int main()
{
	int a, b, c, d, e, f, allsum, allmult, diff;
	printf("input a,b,c,d,e,f");
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	
	allsum = a + b + c + d + e + f;
	allmult = a * b * c * d * e * f;
	if (allsum > allmult) {
		diff = allsum - allmult;
	}
	if (allmult > allsum) {
		diff = allmult - allsum;
	}
	printf("result: %d", diff);
	
	return 0;
}
