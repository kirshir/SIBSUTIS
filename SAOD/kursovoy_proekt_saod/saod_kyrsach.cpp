// Вариант 75   B - 2   C - 3   S - 3   D - 1   E - 3 
// База данных - 2
// Ваpианты условий упоpядочения и ключи поиска (К) - по дате(!) pождения, К = год pождения.
// Merge Sort
// Типы деревьев поиска - АВЛ-дерево
// Методы кодирования - Код Фано

#include <stdio.h>
#include <stdlib.h>

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


void IndexFillInc(Employee *Employee_head, IndexEntry **index_head) {
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


void mergeSort(Employee *Employee_head, Employee *Employee_tail, IndexEntry *&index_head, IndexEntry *&index_tail) {
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
	entry->next = NULL;
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
	int first = -1;

	while(L < R) {
		int m = (L + R) / 2;
		int employeeYear = extractYear(index_array[m].Employee->birthDate);

		if (employeeYear == year) {
			first = m;
			R = m;
		} else if (employeeYear < year) {
			L = m + 1;
		} else {
			R = m;
		}
 	}

	if (first == -1) {
		printf("Nothing found.\n");
		return;
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


void displayRecordsSorted(IndexEntry *index_head) {
	int startIndex = 0;
	char choice = 'y';
	IndexEntry *currentEntry = index_head;

	while(choice == 'y' && currentEntry != NULL) {
		printf("\n");
		for (int i = 0; i < 20 && currentEntry != NULL; i++) {

			Employee *current = currentEntry->Employee;

			printf("Fullname: %s\n", current->fullname);
            printf("Department number: %d\n", current->departmentNumber);
            printf("Position: %s\n", current->position);
            printf("Birthdate: %s\n", current->birthDate);
            printf("------------------------\n");

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
		printf("Fullname: %s\n", current->fullname);
        printf("Department number: %d\n", current->departmentNumber);
        printf("Position: %s\n", current->position);
        printf("Birthdate: %s\n", current->birthDate);
        printf("------------------------\n");
        
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
	while (q->head != NULL) {
		IndexEntry *entry = q->head;
		q->head = q->head->next;

		if (q->head == NULL) {
        	q->tail = NULL;
    	}
		Employee *current = entry->Employee;
		printf("Fullname: %s\n", current->fullname);
        printf("Department number: %d\n", current->departmentNumber);
        printf("Position: %s\n", current->position);
        printf("Birthdate: %s\n", current->birthDate);
        printf("------------------------\n");

		free(entry);
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
}


int main() {
	Employee *Employee_head = NULL;
	Employee *Employee_tail = NULL;
	
	loadDataBase(&Employee_head, &Employee_tail, "testBase2.dat");
	

	IndexEntry *index_head = NULL;
	IndexEntry *index_tail = NULL;
	IndexEntry index_array[MAX_EMPLOYEES];
	int c;
	char ch = 'n';
	while (ch != 'y') {
		printf("\n1)View records from file.\n");
		printf("2)Sort records from file.\n");
		printf("3)Find by birthdate.\n");
		printf("4)End session\n");
		printf("What to do (select a number): ");
		scanf("%d", &c);
		int sortFlag = 0;
		switch(c) {
			case 1:
				displayRecords(Employee_head);
				break;
			case 2:
				if (sortFlag == 0) {
					IndexFillInc(Employee_head, &index_head);
					mergeSort(Employee_head, Employee_tail, index_head, index_tail);
					sortFlag = 1;
				}
				displayRecordsSorted(index_head);
				break;
			case 3:
				if (sortFlag == 0) {
					IndexFillInc(Employee_head, &index_head);
					mergeSort(Employee_head, Employee_tail, index_head, index_tail);
					sortFlag = 1;
				}
				int yearToFound;
				printf("The year of birth that needs to be found: ");
				scanf("%d", &yearToFound);
				fillIndexArray(index_head, index_array);
				Queue q;
				q.head = NULL, q.tail = NULL;
				bSearchYear(index_array, yearToFound, &q);
				displayQueue(&q);
				freeQueue(&q);
				break;
			case 4:
				ch = 'y';
				break;
			default:
				printf("Can't do\n");
				break;
		}
		if (c != 4) {
			printf("End session? y/n ");
			getchar();
			scanf("%c", &ch);
		}
	}
	
	freeListEmployee(Employee_head);
	freeListIndex(index_head);
	
	return 0;
}
