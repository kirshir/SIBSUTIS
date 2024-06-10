//Написать функцию вычисления cosinus с помощью ряда Тейлора  cosinus(x) =1 - x2/2! + x4/4! … + ((-1)n *x2n)/(2n!)
//с точностью до eps=0.0001. В качестве параметра передать x. 
//Сравнить полученное значение со значением стандартной функции cos(x)

#include <stdio.h>
#include <math.h>

double Fact(int n){
	double fact = 1.0;
	for (int i = 1; i <= n; i++){
		fact *= i;
	}
	return fact;
}

double cosinus(double x){
	double y = 1.0;
	double term = 1.0;
	int n = 1;
	double eps = 0.0001;
	
	while(fabs(term) >= eps) {
		term = (pow(-1.0, n) * pow(x, 2 * n)) / Fact(2 * n);
		y += term;
		n++;
	}
	
	return y;
	
}
int main(){
	double x;
	printf("x:");
	scanf("%lf", &x);
	
	double My_Cos = cosinus(x);
	double Regular_Cos = cos(x);
	
	printf("My cos: %lf\n", My_Cos);
	printf("Regular cos: %lf\n", Regular_Cos);
	
	return 0;
}

