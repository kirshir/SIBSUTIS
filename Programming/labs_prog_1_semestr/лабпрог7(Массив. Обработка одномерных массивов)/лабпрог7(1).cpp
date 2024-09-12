
#include <stdio.h>
#include <math.h>
int main(){
	float a = 2.14, b = -4.21, c = 3.25;
	float xnach = -4.5, xkon = -33.5, y;
	float A[59]; 
	int i=0;
	
	do {
		y = a*pow(xnach,2)*sin(xnach) + b*xnach +c;
		A[i] = y;
		xnach -= 0.5;
		i++;
	}	while (xnach >= xkon);
	

	int size = sizeof(A) / sizeof(A[0]);
	
	for (int i=0; i<size-1; i++){
		for (int j=0; j<size-1-i; j++) {
			if (A[j] < A[j+1]) {
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	for (int i=0; i<size; i++) {
		printf("%f ", A[i]);
	}
	return 0;
}
