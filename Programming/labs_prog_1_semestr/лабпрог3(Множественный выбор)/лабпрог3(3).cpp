//� ��������� ��������� ���� ����� ��������� ��������: �����, ������, ����, ����, ������, ����, 
//������, ����, ��������, �����, ������, ������.
//��������, ��� 2008 � ��� �����, �������� ���������, ������������ �������� ���� �� ��� ������.

#include <stdio.h> 
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int year;
	printf("������� ���\n");
	scanf("%d", &year);
	if (year > 0) {
		float a;
		int b;
		a = year % 12;
		b = int(a);
		switch(b){
			case 4:
				printf("��� �����\n");
				break;
			case 5:
				printf("��� ������\n");
				break;
			case 6:
				printf("��� �����\n");
				break;
			case 7:
				printf("��� �����\n");
				break;
			case 8:
				printf("��� �������\n");
				break;
			case 9:
				printf("��� ����\n");
				break;
			case 10:
				printf("��� ������\n");
				break;
			case 11:
				printf("��� ����\n");
				break;
			case 0:
				printf("��� ��������\n");
				break;
			case 1:
				printf("��� ������\n");
				break;
			case 2:
				printf("��� ������\n");
				break;
			case 3:
				printf("��� ������\n");
				break;
			default:
				return 0;
		}
	}
	else printf("������������ ���");
	return 0;
}
