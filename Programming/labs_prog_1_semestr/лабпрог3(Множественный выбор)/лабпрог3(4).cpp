//�������� �����  ������ � � ���  D. ����������  ���������� ����� ��� � ���� �, ��������������� ���� ����.

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int day, month, alldays = 0;
	printf("������� ����:\n");
	scanf("%d", &day);
	printf("������� �����:\n");
	scanf("%d", &month);
	if (day>0 && day<=31) { 
		switch(month) {
			case 12:
				alldays += 30; //november
			case 11:
				alldays += 31;
			case 10:
				alldays += 30;
			case 9:
				alldays += 31; //august
			case 8:
				alldays += 31;
			case 7:
				alldays += 30; //june
			case 6:
				alldays += 31;
			case 5:
				alldays += 30;
			case 4:
				alldays += 31;
			case 3:
				alldays += 28;//february
			case 2:
				alldays += 31;
			case 1:
				alldays += day;
				break;
			default:
				printf("�������� �����\n");
			return 0;
		}
	printf("���������� ����� ��� � ����: %d", alldays);
	}
	else printf("�������� ���������� ����\n");
	return 0;
}
