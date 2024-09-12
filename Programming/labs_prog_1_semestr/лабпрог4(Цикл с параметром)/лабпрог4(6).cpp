//6) S= 1 - 2 + 3 - 4 + ...  N , N > 0 выводится с клавиатуры.(n=20, s=-10)

#include <stdio.h>

int main() {
	int s=0, n;
	printf("Input n\n");
	scanf("%d", &n);
	int m = 1;
	
	for (int i = 1; i<=n; i++){
		s += i*m;
		m =-m;
	}
	printf("%d", s);
	return 0;
}
