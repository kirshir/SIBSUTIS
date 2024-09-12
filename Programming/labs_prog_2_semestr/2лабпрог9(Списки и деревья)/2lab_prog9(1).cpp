#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char lastname[16];
	int grades[4];
	struct Student *next;
};

struct Student* create(char lastname[], int grades[]) {
	struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
	if (newNode == NULL) {
		printf("Memory Error\n");
		exit(1);
	}
	
	
	strcpy(newNode->lastname, lastname);
	memcpy(newNode->grades, grades, sizeof(newNode->grades));
	newNode->next = NULL;
	return newNode;
}

struct Student* add(struct Student *head, char lastname[], int grades[]) {
	if (head == NULL) {
		head = create(lastname, grades);
	} else {
		struct Student *cursor = head;
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		struct Student *newNode = create(lastname, grades);
		cursor->next = newNode;
	}
	return head;
}

void print_list(struct Student *head) {
	while (head) {
		printf("%s: ", head->lastname);
		for (int i = 0; i < 4; i++){
			printf("%d ", head->grades[i]);
		}
		printf("\n");
		head = head->next;
	}
}

void sort(struct Student *head) {
	struct Student* cursor;
	if (head == NULL){
		return;
	}
	char temp_lastname[16];
	int temp_grades[4];
	int swapped;
	do {
		swapped = 0;
		cursor = head;
		while (cursor->next != NULL) {
			if (strcmp(cursor->lastname, cursor->next->lastname) > 0) {
				strcpy(temp_lastname, cursor->lastname);
				memcpy(temp_grades, cursor->grades, sizeof(cursor->grades));
				
				strcpy(cursor->lastname, cursor->next->lastname);
				memcpy(cursor->grades, cursor->next->grades, sizeof(cursor->next->grades));
				
				strcpy(cursor->next->lastname, temp_lastname);
				memcpy(cursor->next->grades, temp_grades, sizeof(temp_grades));
				swapped = 1;
			}
			cursor = cursor->next;
		}
	} while (swapped);
}

void freeSpisok(struct Student* students) {
	struct Student* temp;
	while(students != NULL) {
		temp = students;
		students = students->next;
		free(temp);
	}
}

int main() {
	struct Student *students = NULL;
	int grades1[] = {5, 4, 5, 4};
	int grades2[] = {5, 5, 5, 4};
	int grades3[] = {3, 4, 4, 4};
	int grades4[] = {4, 3, 5, 5};
	int grades5[] = {3, 4, 4, 3};
	students = add(students, "Shirokov", grades1);
	students = add(students, "Gromova", grades2);
	students = add(students, "Ivanov", grades3);
	students = add(students, "Avdeev", grades4);
	students = add(students, "Sharikov", grades5);
	printf("Original Spisok:\n");
	print_list(students);
	
	printf("\nSorted Spisok:\n");
	sort(students);
	print_list(students);
	
	freeSpisok(students);
	return 0;
}
