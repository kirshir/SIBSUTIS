#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char lastname[16];
	int grades[4];
	struct Student* l;
	struct Student* r;
};

struct Student* create(char lastname[], int grades[]) {
	struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
	if (newNode == NULL) {
		printf("Memory Error\n");
		exit(1);
	}
	strcpy(newNode->lastname, lastname);
	memcpy(newNode->grades, grades, sizeof(newNode->grades));
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
}

struct Student* add(struct Student *root, char lastname[], int grades[]) {
	if (root == NULL) {
		root = create(lastname, grades);
	}
	if (strcmp(lastname, root->lastname) < 0) {
		root->l = add(root->l, lastname, grades);
	}
	else if (strcmp(lastname, root->lastname) > 0) {
		root->r = add(root->r, lastname, grades);
	}
	return root;
}

void printTreeAscending(struct Student* root) {
	if (root != NULL) {
		printTreeAscending(root->l);
		printf("%s ", root->lastname);
		for (int i = 0; i < 4; i++) {
			printf("%d ", root->grades[i]);
		}
		printf("\n");
		printTreeAscending(root->r);
	}
}

void printTreeDescending(struct Student* root) {
	if (root != NULL) {
		printTreeDescending(root->r);
		printf("%s ", root->lastname);
		for (int i = 0; i < 4; i++) {
			printf("%d ", root->grades[i]);
		}
		printf("\n");
		printTreeDescending(root->l);
	}
}

void freeTree(struct Student* root) {
	if (root != NULL) {
		freeTree(root->l);
		freeTree(root->r);
		free(root);
	}
}

struct Student* searchTree(struct Student *root, char newlastname[]) {
	if (root == NULL || strcmp(newlastname, root->lastname) == 0) {
		return root;
	}
	if (strcmp (newlastname, root->lastname) < 0) {
		return searchTree(root->l, newlastname);
	}
	else if (strcmp (newlastname, root->lastname) > 0) {
		return searchTree(root->r, newlastname);
	}
}

int main() {
	struct Student* root = NULL;
	int grades1[] = {5, 4, 5, 4};
	int grades2[] = {5, 5, 5, 4};
	int grades3[] = {3, 4, 4, 4};
	int grades4[] = {4, 3, 5, 5};
	int grades5[] = {3, 4, 4, 3};
	root = add(root, "Shirokov", grades1);
	root = add(root, "Gromova", grades2);
	root = add(root, "Ivanov", grades3);
	root = add(root, "Avdeev", grades4);
	root = add(root, "Sharikov", grades5);
	
	printf("Ascending Tree:\n");
	printTreeAscending(root);
	
	printf("\nDescending Tree:\n");
	printTreeDescending(root);
	
	char newlastname[16];
	printf("\nNeed to find by lastname: ");
	scanf("%s", &newlastname);
	struct Student* found = searchTree(root, newlastname);
	if (found != NULL) {
		printf("Found: %s ", found->lastname);
		for (int i = 0; i < 4; i++) {
			printf("%d ", found->grades[i]);
		}
		printf("\n:)");
	}
	else {
		printf("Nothing found\n:(");
	}
	
	freeTree(root);
	return 0;
}
