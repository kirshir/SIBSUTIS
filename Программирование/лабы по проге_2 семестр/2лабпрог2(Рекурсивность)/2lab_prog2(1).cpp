// ������ � ����������� ������� � ���������� ������������������ ����� ��������������� ������ ����,
//� ������� �� ����� ������ ������������� �����. ������ �� ������������.
#include <stdio.h>

int Numbers(){
	printf("Choose the number:");
	int num;
	scanf("%d", &num);
	if (num != 0)
		Numbers();
	if (num > 0)
		printf("%d ", num);
}

int main() {
	Numbers();
	return 0;
}
