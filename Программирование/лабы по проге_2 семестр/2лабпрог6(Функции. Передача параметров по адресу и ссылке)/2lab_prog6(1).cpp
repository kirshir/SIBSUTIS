//параметры указатели 
#include <stdio.h>
#include <math.h>

int P_S(float a, float b, float c, float *P, float *S){
	if(a + b > c && a + c > b && b + c > a) {
		*P = a + b + c;
		float p = *P / 2;
		*S = sqrt(p * (p - a) * (p - b) * (p - c));
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	float a, b, c;
    printf("length of side a = ");
    scanf("%f", &a);
    
    printf("length of side b = ");
    scanf("%f", &b);
    
    printf("length of side c = ");
    scanf("%f", &c);
    
    float P, S;
    if(P_S(a, b, c, &P, &S)){
    	printf("P = %.3f\n", P);
    	printf("S = %.3f\n", S);
	}
	else {
		printf("A triangle with these sides does not exist\n");
	}
    return 0;
}
