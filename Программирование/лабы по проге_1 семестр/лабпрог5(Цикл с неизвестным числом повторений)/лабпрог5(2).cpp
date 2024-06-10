//2. Найти наибольшее и наименьшее значение функции y= (a*x^2+b*x+c)*sin(x) 
//при изменении x от xнач  до xкон  с шагом h.  Вывести значения y. Исходные данные:
//a  = 2.14;  b= - 4.21;  c = 3.25; xнач= -4.5; xкон = -13.5; h= 0.5 .
//(ответ min=-361.783, max=308.497)

#include <stdio.h>
#include <math.h>

int main() {
	float a = 2.14, b = -4.21, c = 3.25;
	float xnach = -4.5, xkon = -13.5, ymin = 1., ymax = 1., y;
	ymax = (a*pow(xnach,2)+ b*xnach + c) * sin(xnach);
	ymin = ymax;

	do {
		y = (a*pow(xnach,2)+ b*xnach + c) * sin(xnach);
		if (y > ymax)  
			ymax = y;
		if (y < ymin)
			ymin = y;
		//printf("%f %f %f\n", ymin, ymax, xnach);
		xnach -= 0.5;
	}	while (xnach >= xkon);
	printf("ymin=%0.3f ymax=%0.3f", ymin, ymax);
	return 0;
	
}
