//2. ��������  ����� ����� �. ���� -9<=c<=9 ������� 
//�������� ����� � ��������� ����� � ������ �����, � ��������� ������
// - ��������������� ��������� � ��������� ����.

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int c;
	while(true){
	printf("������� ����� �����\n");
	scanf("%d", &c);
	
	switch(c) {
		case -9:
			printf("����� ������\n");
			break;
		case -8:
			printf("����� ������\n");
			break;
		case -7:
			printf("����� ����\n");
			break;
		case -6:
			printf("����� �����\n");
			break;
		case -5:
			printf("����� ����\n");
			break;
		case -4:
			printf("����� ������\n");
			break;
		case -3:
			printf("����� ���\n");
			break;
		case -2:
			printf("����� ���\n");
			break;
		case -1:
			printf("����� ����\n");
			break;
		case 0:
			printf("����\n");
			break;
		case 1:
			printf("����\n");
			break;
		case 2:
			printf("���\n");
			break;
		case 3:
			printf("���\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("����\n");
			break;
		case 6:
			printf("�����\n");
			break;
		case 7:
			printf("����\n");
			break;
		case 8:
			printf("������\n");
			break;
		case 9:
			printf("������\n");
			break;
		default:
			printf("������������ �����\n");	
	}
	}
	return 0;
}
