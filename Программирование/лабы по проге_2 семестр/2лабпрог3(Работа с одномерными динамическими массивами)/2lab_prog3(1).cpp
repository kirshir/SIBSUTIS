#include <stdio.h>
#include <stdlib.h>

int main(){
	int *b;
	int n;
	printf("Massive size:");
	scanf("%d", &n);
	
	b = (int *) malloc(n * sizeof(int));
	if (b == NULL) {
		printf("ERROR");
		return 1;
	}
	for (int i = 0; i < n; i++){
		b[i] = rand() % 100 - 50;
	}
	for (int i = 0; i < n; i++){
		printf("%d ", b[i]);
	}
	printf("\n\n");
	
	int m = 0;
	int k = 0;
	for (int i = 0; i < n; i++){
		if (b[i]>= 0){
			m++;
		}
		if (b[i] < 0){
			k++;
		} 
	}
	int *c;
	c = (int *) malloc(m * sizeof(int));
	if (c == NULL){
		printf("ERROR");
		return 1;
	}
	int t = 0;
	for (int i = 0; i < n; i++){
		if (b[i] >= 0){
			c[t] = b[i];
			t++;
		}
	}
	for (int i = 0; i < t; i++){
		printf("%d ", c[i]);
	}
	printf("\n\n");
	
	int *d;
	d = (int *) malloc(k * sizeof(int));
	if (d == NULL){
		printf("ERROR");
		return 1;
	}
	
	int v = 0;
	for (int i = 0; i < n; i++){
		if (b[i] < 0){
			d[v] = b[i];
			v++;
		}
	}
	for (int i = 0; i < v; i++){
		printf("%d ", d[i]);
	}
	free(c);
	free(d);
	free(b);
	return 0;
}
