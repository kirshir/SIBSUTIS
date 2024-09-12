#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
int count = 1;

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

void insert(Node *hashTable[], int key, int m) {
    int index = hash(key, m);
    Node *newNode = push(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int count_Collisions(Node *hashTable[], int m) {
    int collisions = 0;
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != NULL && hashTable[i]->next != NULL) {
            Node *p = hashTable[i]->next;
            while(p != NULL) {
                collisions++;
                p = p->next;
            }
        }
    }
    return collisions;
}

void print_HashTable(Node *hashTable[], int m) {
    printf("Hash Table:\n");
    for (int i = 0; i < m; i++) {
        printf("[%d]: ", i);
        Node *p = hashTable[i];
        while (p != NULL) {
            printf("%d -> ", p->key);
            p = p->next;
        }
        printf("NULL\n");
    }
}

void FillRand(Node *hashTable[], int n, int m) {
    for (int i = 0; i < n; i++) {
        int key = rand() % (2 * n); 
        insert(hashTable, key, m);
    }
}

Node *search(Node *hashTable[], int key, int m, int *count) {
    int index = hash(key, m);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key)
            return hashTable[index];
        hashTable[index] = hashTable[index]->next;
        (*count)++;
    }
    return NULL;
}

int main() {
	setlocale(LC_ALL, "Russian");
    srand(time(0));
    // int n = 50; 
    // int m = n / (2 * log2(n)); 
    // Node *hashTable[m] = {NULL};

    // FillRand(hashTable, n, m);
    // print_HashTable(hashTable, m);

    // int collisions = count_Collisions(hashTable, m);
    // printf("Number of collisions: %d\n", collisions);

    int m = 100 / (2 * log2(100)); 
    Node *hashTabl[m] = {NULL};
    insert(hashTabl, 1, m);
    insert(hashTabl, 2, m);
    insert(hashTabl, -3, m);
    insert(hashTabl, 15, m);
    insert(hashTabl, 10, m);
    insert(hashTabl, 5, m);
    insert(hashTabl, -5, m);
    insert(hashTabl, 8, m);
    print_HashTable(hashTabl, m);
    int keyToSearch = -3;
    Node *result = search(hashTabl, keyToSearch, m, &count);
    if (result != NULL) {
        printf("Element with key %d found at index %d! and at position %d\n", keyToSearch, hash(keyToSearch, m), count);
    } else {
        printf("Element with key %d not found.\n", keyToSearch);
    }


	printf("\n Размер \tКол-во исходных\t  Кол-во \n");
    printf("хеш-табл.\t  символов\t    коллизий\n");
    for (int i = 0; i < 10; i++) {
        int n = 100;
        int m = 11 + rand() % 93;
        int collisions = 0;
        Node *hashTable[m] = {NULL};
        FillRand(hashTable, n, m); 
        collisions = count_Collisions(hashTable, m); 
        printf("\t%d\t\t%d\t\t%d\n", m, n, collisions);
    }

    return 0;
}

