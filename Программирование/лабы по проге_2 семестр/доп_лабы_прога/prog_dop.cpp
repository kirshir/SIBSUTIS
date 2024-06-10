#include <stdio.h>
//0 - закрыта
//1 - открыта
int main() {
	int size = 100;
	int doors[size];
	for (int i = 0; i < size; i++){
		doors[i] = 0;
	}
	for (int i = 1; i < size + 1; i++){
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < size; i++){
		printf("%d ", doors[i]);
	}
	printf("\n\n");
	for (int N = 1; N <= size; N++){
		for (int i = 0; i < size; i++){
			if ((i + 1) % N == 0){
				if (doors[i] == 0){
					doors[i] = 1;
				}
				else doors[i] = 0;
			}
		}
	}
	for (int i = 1; i < size + 1; i++){
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < size; i++){
		printf("%d ", doors[i]);
	}
	printf("\n");
	int open = 0;
	for (int i = 0; i < size; i++){
		if (doors[i] == 1){
			open++;
		}
	}
	printf("%d", open);
	return 0;
}
