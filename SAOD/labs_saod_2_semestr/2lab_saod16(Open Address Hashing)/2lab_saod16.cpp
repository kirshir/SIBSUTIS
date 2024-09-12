#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
int linearCollisions = 0;
int squareCollisions = 0;

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *push(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->next = NULL;
    return p;
}

int hash(int key, int m) {
    if(key >= 0) {
        return key % m;
    } else {
        return (m + (key % m)) % m;
    } 
}

int linearInsert(Node *hashTable[], int key, int m) {
	Node *newNode = push(key);
	int index = hash(key, m);
	int currentIndex = index;
	for (int i = 1; i <= m; i++) {
		if (hashTable[currentIndex] == NULL) {
			hashTable[currentIndex] = newNode;
			return currentIndex;
		}
		linearCollisions++;
		currentIndex = (index + i) % m; 
	}
	free(newNode);
	return -1;
}

int squareInsert(Node *hashTable[], int key, int m) {
	Node *newNode = push(key);
	int index = hash(key, m);
	int currentIndex = index;
	for (int i = 1; i <= m; i++) {
		if (hashTable[currentIndex] == NULL) {
			hashTable[currentIndex] = newNode;
			return currentIndex;
		}
		squareCollisions++;
		currentIndex = (index + i * i) % m; 
	}
	free(newNode);
	return -1;
}

int linearSearch(Node *hashTable[], int key, int m) {
    int index = hash(key, m);
    int currentIndex = index;
    int i = 1;
    while (hashTable[currentIndex] != NULL) {
        if (hashTable[currentIndex]->key == key) {
            return currentIndex;
        }
        currentIndex = (index + i) % m;
        i++;
        if (currentIndex == index)
            break;
    }
    return -1; 
}

int squareSearch(Node *hashTable[], int key, int m) {
    int index = hash(key, m);
    int currentIndex = index;
    int i = 1;
    while (hashTable[currentIndex] != NULL) {
        if (hashTable[currentIndex]->key == key) {
            return currentIndex;
        }
        currentIndex = (index + i * i) % m;
        i++;
        if (currentIndex == index)
            break;
    }
    return -1; 
}

void FillRand(Node *hashTable3[], Node *hashTable4[], int n, int m) {
    for (int i = 0; i < n; i++) {
        int key = rand() % (2 * n);
		linearInsert(hashTable3, key, m); 
        squareInsert(hashTable4, key, m);
    }
}

void print_HashTables(Node *hashTable1[], Node *hashTable2[], int m) {
    printf("Hash Table1:       Hash Table2:\n");
    for (int i = 0; i < m; i++) {
        printf("[%d]: ", i);
        Node *p = hashTable1[i];
        while (p != NULL) {
            printf("%d", p->key);
            p = p->next;
        }
        printf("            [%d]: ", i);
        Node *t = hashTable2[i];
        while (t != NULL) {
            printf("%d", t->key);
            t = t->next;
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n = 20;
	int m = 19;
	
	Node *hashTable1[m];
	Node *hashTable2[m];
	for (int i = 0; i < m; i++) {
        hashTable1[i] = NULL;
        hashTable2[i] = NULL;
    }
    
    printf("m = %d\n", m);
    printf("Линейные пробы             Квадратичные пробы\n");
	for (int i = 0; i < n; i++) {
		int key = rand() % (2 * n);
		int index1 = linearInsert(hashTable1, key, m);
		int index2 = squareInsert(hashTable2, key, m);
		if (index1 != -1) {
			printf("%d - [%d]", key, index1);		
		}
		else printf("%d - Переполнение таблицы", key);
		if (index2 != -1) {
			if (index1 != -1) {
				printf("                      %d - [%d]\n", key, index2);
			}
			else printf("      %d - [%d]\n", key, index2);
		}
		else {
			if (index1 != -1) {
				printf("                      %d - Переполнение таблицы\n", key);
			}
			else printf("     %d - Переполнение таблицы\n", key);
		}
	}
	printf("\n\n");
	print_HashTables(hashTable1, hashTable2, m);
    
	int keyToSearch = 33;
	int result1 = linearSearch(hashTable1, keyToSearch, m);
	int result2 = squareSearch(hashTable2, keyToSearch, m);
	
	printf("Linear Search:\n");
	if (result1 != -1) {
        printf("Element with key %d found at index %d!\n", keyToSearch, result1);
    } else {
        printf("Element with key %d not found.\n", keyToSearch);
    }
    
    printf("Square Search:\n");
    if (result2 != -1) {
        printf("Element with key %d found at index %d!\n", keyToSearch, result2);
    } else {
        printf("Element with key %d not found.\n", keyToSearch);
    }
	printf("\n\n");
	
	printf("  Размер\tКол-во исходных\t\tКол-во коллизий\n");
	printf("Хэш-Таблицы\t  символов\t   Линейные пробы   Квадратичные пробы\n");
    n = 100;
    for (int i = 0; i < 10; i++) {
    	m = 11 + rand() % 92;
		linearCollisions = 0;
		squareCollisions = 0;
		Node *hashTable3[m];
		Node *hashTable4[m];
		for (int j = 0; j < m; j++) {
	        hashTable3[j] = NULL;
	        hashTable4[j] = NULL;
	    }
	    FillRand(hashTable3, hashTable4, n, m);
		printf("   %d\t\t    %d\t\t\t%d\t\t%d\n", m, n, linearCollisions, squareCollisions);
	}
	
	return 0;
}
