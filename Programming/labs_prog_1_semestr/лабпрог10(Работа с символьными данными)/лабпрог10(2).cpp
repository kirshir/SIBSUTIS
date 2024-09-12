//2.Во введенном тексте найти количество повторений каждого слова. 
//Одинаковые слова дважды не выводить.
#include <stdio.h>
#include <string.h>

int main() {
	char text[1000];
	fgets(text, 1000, stdin);
	
	char words[100][100];
	int word_count[100] = {0};
	int word_index = 0;
	
	char *wor = strtok(text, " \n");
	while (wor != NULL) {
		int found = 0;
		for (int i = 0; i < word_index; i++) {
			if (strcmp(words[i], wor) == 0) {
				word_count[i]++;
				found = 1;
				break;
			}
		}
		if (!found) {
			strcpy(words[word_index], wor);
			word_count[word_index]++;
			word_index++;
		}
		wor = strtok(NULL, " \n");
	} 
	for (int i = 0; i < word_index; i++) {
		printf("%s: %d\n", words[i], word_count[i]);
	}
	return 0;
}

