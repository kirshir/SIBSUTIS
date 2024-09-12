//В китайском гороскопе года носят следующие названия: крыса, корова, тигр, заяц, дракон, змея, 
//лошадь, овца, обезьяна, петух, собака, свинья.
//Учитывая, что 2008 – год крысы, написать программу, определяющую название года по его номеру.

#include <stdio.h> 
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int year;
	printf("Введите год\n");
	scanf("%d", &year);
	if (year > 0) {
		float a;
		int b;
		a = year % 12;
		b = int(a);
		switch(b){
			case 4:
				printf("Год крысы\n");
				break;
			case 5:
				printf("Год коровы\n");
				break;
			case 6:
				printf("Год тигра\n");
				break;
			case 7:
				printf("Год зайца\n");
				break;
			case 8:
				printf("Год дракона\n");
				break;
			case 9:
				printf("Год змеи\n");
				break;
			case 10:
				printf("Год лошади\n");
				break;
			case 11:
				printf("Год овцы\n");
				break;
			case 0:
				printf("Год обезьяны\n");
				break;
			case 1:
				printf("Год петуха\n");
				break;
			case 2:
				printf("Год собаки\n");
				break;
			case 3:
				printf("Год свиньи\n");
				break;
			default:
				return 0;
		}
	}
	else printf("Неподходящий год");
	return 0;
}
