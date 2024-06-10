//5)   S= 0.18x + (0.20x)2 + (0.22x)3 +...+ (0.36x)10;(x=1, s=0.236)

#include <stdio.h>
#include <math.h>

int main() {
	int x, n;
	float s = 0;
	printf("Input x\n");
	scanf("%d", &x);
	
	for (float i=0.18, n=1; i<0.37, n<=10; i+=0.02, n++) {
		s += pow(i*x, n);
		//continue;
	}
	printf("s = %0.3f", s);
	return 0;
}
