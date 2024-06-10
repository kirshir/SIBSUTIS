#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void InsertSort(char *words[], int indexes[], int wordCount){
	for (int i = 0; i < wordCount; i++){
		char *key = words[indexes[i]];
		int keyIndexes = indexes[i];
		int j = i - 1;
		while (j >= 0 && strcmp(words[indexes[j]], key) > 0) {
			indexes[j + 1] = indexes[j];
			j = j - 1; 
		}
		indexes[j + 1] = keyIndexes;
	}
}

int main() {
	char line[32];
	char *token;
	char **words = NULL;
	int wordCount = 0;
	FILE *inputfile;
	inputfile = fopen("text1.txt", "r");
	if (inputfile == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	while (fgets(line, sizeof(line), inputfile) != NULL){
		token = strtok(line, " \n");
		while (token != NULL){
			char *newWord = (char *)malloc(strlen(token) + 1);
			if (newWord == NULL) {
				printf("Memory Error\n");
				return 1;
			}
			strcpy(newWord, token);
			words = (char **)realloc(words, (wordCount + 1) * sizeof(char *));
			if (words == NULL) {
				printf("Memory Error\n");
				return 1;
			}
			words[wordCount] = newWord;
			wordCount++;
			token = strtok(NULL, " \n");
		}
	}
	int indexes[wordCount];
	for (int i = 0; i < wordCount; i++){
		indexes[i] = i;
	}
	InsertSort(words, indexes, wordCount);
//	for (int i = 0; i < wordCount; i++){
//		printf("%s\n", words[indexes[i]]);
//	}
	
	FILE *outputfile;
	outputfile = fopen("text2.txt", "w");
	if (outputfile == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	for (int i = 0; i < wordCount; i++){
		int j = 0;
		while(words[indexes[i]][j] != '\0'){
			putc(words[indexes[i]][j], outputfile);
			j++;
		}
		putc('\n', outputfile);
	}
	fclose(outputfile);
	
	outputfile = fopen("text2.txt", "r");
	if (outputfile == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	char line2[16];
	while (fgets(line2, sizeof(line2), outputfile) != NULL) {
		printf("%s", line2);
	}
	
	for (int i = 0; i < wordCount; i++){
		free(words[i]);
	}
	free(words);
	fclose(inputfile);
	fclose(outputfile);
	return 0;
}
