//параметры-ссылки

#include <stdio.h>
#include <math.h>

long long fact(int n) {
	if (n == 0 || n == 1){
		return 1;
	}
	else return n * fact(n - 1);
}

void probability(int n, int m, float p, float q, double &pd, double &pm){
	float C = fact(n) / (fact(m) * fact(n - m)); 
	pd = C * pow(p, m) * pow(q, (n - m));
	pm = C * pow(q, m) * pow(p, (n - m));
}

int main() {
	int n, m;
	printf("How many children = ");
	scanf("%d", &n);
	printf("How many girls or boys = ");
	scanf("%d", &m);
	if (m > n){
		printf("Error. Girls cannot be more than a children");
		return 1;
	}
	if (n == 0 || m == 0){
		printf("Error. Cannot be 0 girls or children");
		return 1;
	}
	float p = 0.45;
	float q = 1 - p;
	double pd, pm;
	probability(n, m, p, q, pd, pm);
	printf("probability of girls = %.4f\n", pd);
	printf("probability of boys = %.4f\n", pm);
 return 0;	
}
