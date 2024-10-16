// Вариант 75   B - 2   C - 3   S - 3   D - 1   E - 3 
// База данных - 2
// Ваpианты условий упоpядочения и ключи поиска (К) - по дате(!) pождения, К = год pождения.
// Merge Sort
// Типы деревьев поиска - АВЛ-дерево
// Методы кодирования - Код Фано

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMPLOYEES 4000

typedef struct Employee {
	struct Employee *next;
	char fullname[31];
	short int departmentNumber;
	char position[23];
	char birthDate[11];
} Employee;


typedef struct IndexEntry {
	struct IndexEntry *next;
	int index;
	Employee *Employee;
} IndexEntry;


typedef struct Queue {
	IndexEntry *head;
	IndexEntry *tail;
} Queue;


typedef struct Vertex {
	Employee *employee;
	int balance;
	Vertex *L;
	Vertex *R;
	Vertex *next;
} Vertex;


Employee *createNode() {
	Employee *newNode = (Employee*)malloc(sizeof(Employee));
	if (newNode == NULL) {
		printf("Memory error.\n");
		exit(1);
	}	
	newNode->next = NULL;
	return newNode;
}


void append(Employee **head, Employee **tail, Employee *data) {
	if (*head == NULL) {
		*head = *tail = data;
	} else {
		(*tail)->next = data;
		*tail = data;
	}
}


void loadDataBase(Employee **head, Employee **tail, const char *filename) {
	FILE *file = fopen(filename, "rb");
	if (file == NULL) {
		printf("Error opening file\n");
		exit(1);
	}
	
	while(!feof(file)) {
		Employee *newEmployee = createNode();
		
		if (fread(newEmployee->fullname, sizeof(char), 30, file) != 30) {
			free(newEmployee);
			break;
		}
        fread(&newEmployee->departmentNumber, sizeof(short int), 1, file);
        fread(newEmployee->position, sizeof(char), 22, file);
        fread(newEmployee->birthDate, sizeof(char), 10, file);

        newEmployee->fullname[30] = '\0';
        newEmployee->position[22] = '\0';
        newEmployee->birthDate[10] = '\0';
		
		append(head, tail, newEmployee); 

	}
	
	fclose(file);
}


void fillEmployeeIndex(Employee *Employee_head, IndexEntry **index_head) {
    Employee *current = Employee_head;
    IndexEntry *prev = NULL;
    int i = 0;
    
    while (current != NULL && i < MAX_EMPLOYEES) {
        IndexEntry *newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
        if (newEntry == NULL) {
            printf("Memory error.\n");
            exit(1);
        }
        newEntry->index = i;
        newEntry->Employee = current;
        newEntry->next = NULL;

        if (prev == NULL) {
            *index_head = newEntry;
        } else {
            prev->next = newEntry;
        }
        
        prev = newEntry;
        current = current->next;
        i++;
    }
}


int compareBirthdate(const char *date1,  const char *date2) {
	int day1, month1, year1;
	int day2, month2, year2;

	sscanf(date1, "%2d-%2d-%2d", &day1, &month1, &year1);
	sscanf(date2, "%2d-%2d-%2d", &day2, &month2, &year2);

	if (year1 != year2) return  year1 - year2;
	if (month1 != month2) return month1 - month2;
	return day1 - day2;
}


int split(IndexEntry *index_head, IndexEntry **a, IndexEntry **b) {
	*a = index_head;
	*b = index_head->next;
	int n = 1;
	IndexEntry *k = *a;
	IndexEntry *p = *b;

	while(p != NULL) {
		n++;
		k->next = p->next;
		k = p;
		p = p->next;
	}
	return n;
}

void merger(IndexEntry **a,  int q, IndexEntry **b, int r, Queue *c) {
	while (q != 0 && r != 0) {
		if(compareBirthdate((*a)->Employee->birthDate, (*b)->Employee->birthDate) <= 0) {
			if (c->head == NULL) {
				c->head = *a;
			} else {
				c->tail->next = *a;
			}
			c->tail = *a;
			*a = (*a)->next;
			q--;
		} else {
			if (c->head == NULL) {
				c->head = *b;
			} else {
				c->tail->next = *b;
			}
			c->tail = *b;
			*b = (*b)->next;
			r--;
		}
	}

	while(q > 0) {
		c->tail->next = *a;
		c->tail = *a;
		*a = (*a)->next;
        q--;
	}
	while (r > 0) {
        c->tail->next = *b;
        c->tail = *b;
        *b = (*b)->next;
        r--;
    }
}


void mergeSort(IndexEntry *&index_head, IndexEntry *&index_tail) {
	IndexEntry *a = NULL;
	IndexEntry *b = NULL;

	int n = split(index_head, &a, &b);
	int p = 1;
	int q, r;
	Queue c[2];
	while(p < n) {
		c[0].tail = (IndexEntry *)&(c[0].head);
		c[1].tail = (IndexEntry *)&(c[1].head);
		int i = 0;
		int m = n;
		while(m > 0) {
			if (m >= p) {
				q = p;
			} else {
				q = m;
			}
			m -= q;
			if (m >= p) {
				r = p;
			} else {
				r = m;
			}
			m -= r;
			merger(&a, q, &b, r, &c[i]);
			i = 1 - i;
		}
		a = c[0].head;
		b = c[1].head;
		p *= 2;
	}
	c[0].tail->next = NULL;
	index_head = c[0].head;
	index_tail = c[0].tail;
}


void fillIndexArray(IndexEntry *index_head, IndexEntry index_array[]) {
	IndexEntry *current = index_head;
	int i = 0;

	while(current != NULL && i < MAX_EMPLOYEES) {
		index_array[i].index = i;
		index_array[i].Employee = current->Employee;
		current = current->next;
		i++;
	}
}


int extractYear(const char *birthDate) {
    int day, month, year;
    sscanf(birthDate, "%*2d-%*2d-%2d", &year);
    return year;
}


void addQueue(Queue *q, IndexEntry *entry) {
	if (q->tail == NULL) {
		q->head = entry;
		q->tail = entry;
	} else {
		q->tail->next = entry;
		q->tail = entry;
	}
}


void bSearchYear(IndexEntry index_array[], int year, Queue *q) {
	int L = 0, R = MAX_EMPLOYEES - 1;
	int first;

	while(L < R) {
		int m = (L + R) / 2;
		int employeeYear = extractYear(index_array[m].Employee->birthDate);

		if (employeeYear < year) {
			L = m + 1;
		} else {
			R = m;
		}
 	}

	if (extractYear(index_array[R].Employee->birthDate) == year) {
		first = L;
	} else {
		printf("Nothing found.\n");
	}

	for (int i = first; i < MAX_EMPLOYEES && extractYear(index_array[i].Employee->birthDate) == year; i++) {
		IndexEntry *entry = (IndexEntry *)malloc(sizeof(IndexEntry));
		if (entry == NULL) {
			printf("Memory Error.\n");
			exit(1);
		}
		entry->Employee = index_array[i].Employee;
        entry->next = NULL;
        addQueue(q, entry);
	}
}

void rotateLL(Vertex *&p) {
    Vertex *q = p->L;
    p->balance = 0;
    q->balance = 0;
    p->L = q->R;
    q->R = p;
    p = q;
}

void rotateRR(Vertex *&p) {
    Vertex *q = p->R;
    p->balance = 0;
    q->balance = 0;
    p->R = q->L;
    q->L = p;
    p = q;
}

void rotateLR(Vertex *&p) {
    Vertex *q = p->L;
    Vertex *r = q->R;
    if (r->balance < 0) {
        p->balance = 1;
    } else {
        p->balance = 0;
    }

    if (r->balance > 0) {
        q->balance = -1;
    } else {
        q->balance = 0;
    }

    r->balance = 0;
    q->R = r->L;
    p->L = r->R;
    r->L = q;
    r->R = p;
    p = r;
}

void rotateRL(Vertex *&p) {
    Vertex *q = p->R;
    Vertex *r = q->L;
    if (r->balance > 0) {
        p->balance = -1;
    } else {
        p->balance = 0;
    }

    if (r->balance < 0) {
        q->balance = 1;
    } else {
        q->balance = 0;
    }

    r->balance = 0;
    q->L = r->R;
    p->R = r->L;
    r->L = p;
    r->R = q;
    p = r;
}

bool addAVL(Vertex *&p, Employee *employee, bool &rost) {
    if (p == NULL) {
        p = (Vertex*)malloc(sizeof(Vertex));
        p->employee = employee;
        p->balance = 0;
        p->L = NULL;
        p->R = NULL;
		p->next = NULL;
        rost = true;
    } else if (strcmp(p->employee->fullname, employee->fullname) > 0) {
        if (addAVL(p->L, employee, rost)) {
            if (rost == true) {
                if (p->balance > 0) {
                    p->balance = 0;
                    rost = false;
                } else if (p->balance == 0) {
                    p->balance = -1;
                    rost = true;
                } else if (p->L->balance < 0) {
                    rotateLL(p);
                    rost = false;
                } else {
                    rotateLR(p);
                    rost = false;
                }
            } 
        } else {
            return false;
        }
    } 
    else if (strcmp(p->employee->fullname, employee->fullname) < 0) {
        if (addAVL(p->R, employee, rost)) {
            if (rost == true) {
                if (p->balance < 0) {
                    p->balance = 0;
                    rost = false;
                } else if (p->balance == 0) {
                    p->balance = 1;
                    rost = true;
                } else if (p->R->balance > 0) {
                    rotateRR(p);
                    rost = false;
                } else {
                    rotateRL(p);
                    rost = false;
                }
            }
        } else {
            return false;
        }
    } else {
        if (strcmp(p->employee->fullname, employee->fullname) == 0) {
			Vertex* current = p;
			while (current->next != NULL) {
				current = current->next;
			}
			Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
			if (newVertex == NULL) {
				printf("Memory Error\n");
				return false;
			}
			newVertex->employee = employee;
			newVertex->balance = 0;
			newVertex->L = NULL;
			newVertex->R = NULL;
			newVertex->next = NULL;
			current->next = newVertex;
			return true;
		} else {
			return false;
		}
    }
    return true;
}

Vertex *createAVL(Queue* q) {
	Vertex* root = NULL;
	bool rost;
	
	while (q->head != NULL) {
		IndexEntry *entry = q->head;
        q->head = q->head->next;

        if (q->head == NULL) {
            q->tail = NULL;
        }

		if(!addAVL(root, entry->Employee, rost)) {
			printf("Error adding to tree!\n");
		}
		
		free(entry);
	}
	return root;
}


char* normalizeString(const char* str) {
    char* normalized = (char*)malloc(strlen(str) + 1);
    if (normalized == NULL) {
        printf("Memory error\n");
		return NULL;
    }
    
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            normalized[j] = tolower(str[i]);
			j++;
        }
    }
    normalized[j] = '\0';

    return normalized;
}


Vertex* treeSearch(Vertex* root, const char* fullname) {
    if (root == NULL) {
        return NULL;
    }

    char* normalizedFullname = normalizeString(fullname);
    char* normalizedVertexName = normalizeString(root->employee->fullname);

    int cmp = strcmp(normalizedVertexName, normalizedFullname);
    
    free(normalizedFullname);
    free(normalizedVertexName);
    
    if (cmp == 0) {
        return root;
    }
    
    if (cmp > 0) {
        return treeSearch(root->L, fullname);
    }
    
    return treeSearch(root->R, fullname);
}


void displaySearchResult(Vertex* result) {
	if (result == NULL) {
		printf("Nothing found\n");
		return;
	}
	Vertex* current = result;
	while (current != NULL) {
		Employee* emp = current->employee;
		printf("%s ", emp->fullname);
        printf("%d ", emp->departmentNumber);
        printf("%s ", emp->position);
        printf("%s\n", emp->birthDate);
		current = current->next;
	}
}


void displayRecordsSorted(IndexEntry *index_head) {
	int startIndex = 0;
	char choice = 'y';
	IndexEntry *currentEntry = index_head;

	while(choice == 'y' && currentEntry != NULL) {
		printf("\n");
		for (int i = 0; i < 20 && currentEntry != NULL; i++) {

			Employee *current = currentEntry->Employee;

			printf("%s ", current->fullname);
            printf("%d ", current->departmentNumber);
            printf("%s ", current->position);
            printf("%s\n", current->birthDate);
        
			currentEntry = currentEntry->next;
			startIndex++;
		}
		

		if (currentEntry != NULL) {
			printf("Show %d records. Continue? (y/n): ", startIndex);
			scanf(" %c", &choice);
			if (choice != 'y' && choice != 'Y') {
                break;
            }
		} else {
			printf("Records finished\n");
			break;
		}
	}
} 


void displayRecords(Employee *head) {
	Employee *current = head;
	int recordCount = 0;
	char choice;
	
	printf("\n");
	while (current) {
		printf("%s ", current->fullname);
        printf("%d ", current->departmentNumber);
        printf("%s ", current->position);
        printf("%s\n", current->birthDate);
        
        recordCount++;
        if (recordCount % 20 == 0 && recordCount % MAX_EMPLOYEES != 0) {
            printf("Show %d records. Continue? (y/n): ", recordCount);
            scanf(" %c", &choice);
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }

		if (recordCount % MAX_EMPLOYEES == 0) {
			printf("Records finished\n");
		}
        
        current  = current->next;
	}
}


void displayQueue(Queue *q) {
	if (q->head == NULL) {
		return;
	}
	IndexEntry *current = q->head;

	while (current != NULL) {
		Employee *emp = current->Employee;
		printf("%s ", emp->fullname);
        printf("%d ", emp->departmentNumber);
        printf("%s ", emp->position);
        printf("%s\n", emp->birthDate);
		current = current->next;
	}
}


void displayTree(Vertex* root) {
	if (root != NULL) {
		displayTree(root->L);
		printf("%s ", root->employee->fullname);
		printf("%d ", root->employee->departmentNumber);
		printf("%s ", root->employee->position);
		printf("%s\n", root->employee->birthDate);

		Vertex* current = root->next;
		while (current != NULL) {
			printf("%s ", current->employee->fullname);
			printf("%d ", current->employee->departmentNumber);
			printf("%s ", current->employee->position);
			printf("%s\n", current->employee->birthDate);
			current = current->next;
		}
		displayTree(root->R);
	}
}


void freeListEmployee(Employee *head) {
	Employee *temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}


void freeListIndex(IndexEntry *head) {
	IndexEntry *temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void freeQueue(Queue *q) {
	IndexEntry *entry = q->head;
	while(entry != NULL) {
		IndexEntry *temp = entry;
		entry = entry->next;
		free(temp);
	}
	q->head = NULL;
	q->tail = NULL;
}


void freeTree(Vertex* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->L);
    freeTree(root->R);
	Vertex* current = root;
	while (current != NULL) {
		Vertex* nextVertex = current->next;
		free(current);
		current = nextVertex;
	}
}


int main() {
	Employee *Employee_head = NULL;
	Employee *Employee_tail = NULL;
	loadDataBase(&Employee_head, &Employee_tail, "testBase2.dat");
	
	IndexEntry *index_head = NULL;
	IndexEntry *index_tail = NULL;
	IndexEntry index_array[MAX_EMPLOYEES];
	Queue q;
	q.head = NULL, q.tail = NULL;
	int c;
	char ch = 'n';
	while (ch != 'y') {
		printf("\n1)View records from file.\n");
		printf("2)Sort records from file.\n");
		printf("3)Find by birthdate.\n");
		printf("4)Create tree\n");
		printf("5)End session\n");
		printf("What to do (select a number): ");
		scanf("%d", &c);
		switch(c) {
			case 1:
				displayRecords(Employee_head);
				break;
			case 2:
				if (index_head == NULL) {
					fillEmployeeIndex(Employee_head, &index_head);
					mergeSort(index_head, index_tail);
				}
				displayRecordsSorted(index_head);
				break;
			case 3:
				if (index_head == NULL) {
					fillEmployeeIndex(Employee_head, &index_head);
					mergeSort(index_head, index_tail);
				}
				freeQueue(&q);
				int yearToFound;
				printf("The year of birth that needs to be found: ");
				scanf("%d", &yearToFound);
				fillIndexArray(index_head, index_array);
				bSearchYear(index_array, yearToFound, &q);
				displayQueue(&q);
				break;
			case 4:
				if (q.head == NULL) {
					printf("First create a queue (key 3)\n");
				} else {
					Vertex* avlTree = createAVL(&q);
					displayTree(avlTree);
					char searchChoice = 'y';
					while(searchChoice == 'y') {
						printf("Find a record in the tree? (y/n) ");
						getchar();
						scanf("%c", &searchChoice);
						if (searchChoice == 'y' || searchChoice == 'Y') {
							char searchName[31];
							printf("Fullname you need to find: ");
							scanf(" %[^\n]", searchName);
							printf("You entered: %s\n", searchName);
							Vertex* result = treeSearch(avlTree, searchName);
							displaySearchResult(result);
						}
					}
					freeTree(avlTree);
					freeQueue(&q);
				}
				break;
			case 5:
				ch = 'y';
				break;
			default:
				printf("Can't do\n");
				break;
		}
		if (c != 5) {
			printf("End session? y/n ");
			getchar();
			scanf("%c", &ch);
		}
	}
	
	freeListEmployee(Employee_head);
	freeListIndex(index_head);
	freeListIndex(index_tail);
	freeQueue(&q);
	return 0;
}
