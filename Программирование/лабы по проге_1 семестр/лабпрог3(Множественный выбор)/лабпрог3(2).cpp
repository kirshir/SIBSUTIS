//2. Вводится  целое число С. Если -9<=c<=9 вывести 
//величину числа в словесной форме с учетом знака, в противном случае
// - предупреждающее сообщение и повторный ввод.

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int c;
	while(true){
	printf("Введите целое число\n");
	scanf("%d", &c);
	
	switch(c) {
		case -9:
			printf("Минус девять\n");
			break;
		case -8:
			printf("Минус восемь\n");
			break;
		case -7:
			printf("Минус семь\n");
			break;
		case -6:
			printf("Минус шесть\n");
			break;
		case -5:
			printf("Минус пять\n");
			break;
		case -4:
			printf("Минус четыре\n");
			break;
		case -3:
			printf("Минус три\n");
			break;
		case -2:
			printf("Минус два\n");
			break;
		case -1:
			printf("Минус один\n");
			break;
		case 0:
			printf("Ноль\n");
			break;
		case 1:
			printf("Один\n");
			break;
		case 2:
			printf("Два\n");
			break;
		case 3:
			printf("Три\n");
			break;
		case 4:
			printf("Четыре\n");
			break;
		case 5:
			printf("Пять\n");
			break;
		case 6:
			printf("Шесть\n");
			break;
		case 7:
			printf("Семь\n");
			break;
		case 8:
			printf("Восемь\n");
			break;
		case 9:
			printf("Девять\n");
			break;
		default:
			printf("Неподходящее число\n");	
	}
	}
	return 0;
}
