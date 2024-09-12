//9)  S= 1+ x/1! + x2/2!+...+ xN/N!, N>0 вводится с клавиатуры. (x=5, N=10, s=146.38)

#include <stdio.h> 
#include <math.h>

int main()
{
	float s=1, p=1;
	int x = 5, n;
	printf("Input N\n");
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++){
		p *= i;
		s += pow(x,i)/p;
	}
	printf("answer=%0.2f",s);
	return 0;
}
