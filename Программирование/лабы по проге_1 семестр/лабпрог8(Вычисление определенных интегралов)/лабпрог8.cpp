//9. f(x)=(2x+lg x)/(1+lg x); a=1; b=10;

#include <math.h>
#include <stdio.h>

int N = 10,N1 = 100,N2 = 1000;
float f(float x){  
  float y = (2*x+log(x))/(1+log(x));
  return y;		
}	 
int main() {
  int N_values[] = {N, N1, N2};
    for (int n=0; n<3; n++) {
        int N = N_values[n];	
		float A[N+1];
		float a = 1, b = 10;
		float h = (b - a)/N;
		int k = 0;
		for (float i = a; i <= b; i = i + h){
		  A[k] = f(i);
		  k++;
		}
		//for (int i=0;i<N+1;i++) printf("%f ",A[i]);
		printf("\n");
		  
		float sum = 0;
		for (int i = 1; i<N; i++) {
		  sum += A[i];
		}
		sum += A[0]/2 + A[N]/2;
		float I1 = h*sum; 
		printf("I1=%f (if N=%d)", I1, N);
		  
		printf("\n");
		  
		float sum1 = 0;
		for (int i=1; i<N; i += 2){
		  sum1 += A[i];
		}
		sum1 *= 4;
		float sum2 = 0;
		for (int i=2; i<=N-2; i +=2){
		  sum2 += A[i];
		}
		sum2 *= 2;
		float allsum = 0;
		allsum = h/3*(A[0] + A[N] + sum1 + sum2);
		printf("I2=%f (if N=%d)\n", allsum, N);
	}
	return 0;
}
