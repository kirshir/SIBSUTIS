//7)   P= M! = 1* 2* 3*...*M, M вводится с клавиатуры; (m=5, P=120)

#include <stdio.h>

int main() 
{
	int p=1, m;
	printf("Input\n");
	scanf("%d", &m);
	
	for (int i=1; i<=m; i++){
		p*=i;
	}
	printf("%d", p);
	return 0;
}
