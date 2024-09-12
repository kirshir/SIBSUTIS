//Написать функцию вычисления даты Пасхи по алгоритму Гаусса
#include <stdio.h>

int Pasha_date(int year){
	int a, b, c, d, e, f;
	a = year % 19;
	b = year % 4;
	c = year % 7;
	d = (19 * a + 15) % 30;
	e = (2 * b + 4 * c + 6 * d + 6) % 7;
	f = d + e;
	return f;
}

int main(){
	int year;
	printf("Choose a Year:");
	scanf("%d", &year);
	int f = Pasha_date(year);
	if (f <= 26){
		printf("Pasha date = %d april", 4 + f);
	}
	else if(f > 26){
		printf("Pasha date = %d may", f - 26);
		}
	return 0;
}
