//1)   S= 1+ 2 + 3+...+ 117;  (s=6903)
#include<stdio.h>

int main()
{
 int i, s = 0;
 for(i = 1; i<118; i++)
 	s += i;
 	printf("%d", s);
 	return 0;
}
