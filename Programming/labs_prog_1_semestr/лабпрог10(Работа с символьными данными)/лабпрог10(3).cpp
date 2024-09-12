//Список фамилий вводится через запятую в виде строки. Упорядочить фамилии по алфавиту.

#include <stdio.h>
#include <string.h>

int main() {
	char input[100];
	fgets(input, 100, stdin);
	char surnames[100][100];
	int count = 0;
	
	char *wor = strtok(input, " ,\n");
	while (wor != NULL && count < 100) {
		strcpy(surnames[count], wor);
		count++;
		wor = strtok(NULL, " ,\n");
	}
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (strcmp(surnames[j], surnames[j + 1]) > 0) {
//				char temp[100];
//				strcpy(temp, surnames[j]);
//				strcpy(surnames[j], surnames[j + 1]);
//				strcpy(surnames[j + 1]), temp);
				char *temp = surnames[j];
				surnames[j] = surnames[j + 1];
				surnames[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < count, i++) {
		printf("%s\n", surnames[i]);
	}
//	for (int i = 0; i < count; i++) {
//		printf("%s\n", surnames[i]);
//	}
	return 0;
}
