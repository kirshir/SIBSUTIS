#include <stdio.h>
#include <string.h>

struct Record {
	char firstName[30];
    char lastName[30];
    char phoneNumber[15];
    int age;
};

void InsertSortLastAndFirstName(struct Record arr[], int indexes1[], int size, int (*Compare)(struct Record*, struct Record*)) {
	for (int i = 1; i < size; i++) {
	    struct Record key = arr[indexes1[i]];
	    int keyIndex = indexes1[i];
	    int j = i - 1;
	    while (j >= 0 && Compare(&arr[indexes1[j]], &key) > 0) {
	      indexes1[j + 1] = indexes1[j]; 
	      j = j - 1; 
	    }
	    indexes1[j + 1] = keyIndex; 
  	}
}

int CompareByLastAndFirstName(struct Record* a, struct Record* b) {
	int result = strcmp(a->lastName, b->lastName);
    if (result == 0) {
    	result = strcmp(a->firstName, b->firstName);
    }
    return result;
}


void InsertSortAge(struct Record arr[], int indexes2[], int size){
	for (int i = 1; i < size; i++){
		int t = indexes2[i];
		int j = i - 1;
		while (j >= 0 && arr[t].age < arr[indexes2[j]].age){
			indexes2[j + 1] = indexes2[j];
			j = j - 1;
		}
		indexes2[j + 1] = t;
	}
}

int BSearchAge(struct Record arr[], int indexes[], int size, int X){
	int L = 0, R = size - 1;
	while(L < R){
		int m = (L + R )/ 2;
		if (arr[indexes[m]].age < X){
			L = m + 1;
		}
		else R = m;
	}
	
	if (arr[indexes[R]].age == X) {
		return R;
	}
	else return -1;
}

int BSearchLastName(struct Record arr[], int indexes[], int size, char *X){
	int L = 0, R = size - 1;
	while(L < R){
		int m = (L + R )/ 2;
		int cmp = strcmp(arr[indexes[m]].lastName, X);
		if (cmp < 0){
			L = m + 1;
		}
		else R = m;
	}
	
	if (strcmp(arr[indexes[R]].lastName, X) == 0) {
		return R;
	}
	else return -1;
}


void printRecords(struct Record contacts[], int indexes[], int size) {
    for (int i = 0; i < size; i++) {
    	printf("Name: %s %s, Phone: %s, Age: %d\n", contacts[indexes[i]].firstName, contacts[indexes[i]].lastName, contacts[indexes[i]].phoneNumber, contacts[indexes[i]].age);
    }
}

int main() {
	int size = 5;
	struct Record contacts[size] = {
	    {"Nastya", "Gromova", "9513984375", 19},
	    {"Kirill", "Shirokov", "9513791855", 18},
	    {"Veronika", "Spasskaya", "9966362469", 19},
	    {"Kate", "Shirikova", "4568952352", 17},
	    {"Ilya", "Ivanov", "9876543256", 20}
	};
	int indexes1[size];
	int indexes2[size];
	for (int i = 0; i < size; i++){
		indexes1[i] = i;
		indexes2[i] = i;
	}
	
	int X;
	char lastname[30];
	
	printf("Need to find by age:");
	scanf("%d", &X);
	
	printf("Need to find by lastname:");
	scanf("%s", &lastname);
	
	printf("Original Records:\n");
    printRecords(contacts, indexes1, size);
	
	InsertSortLastAndFirstName(contacts, indexes1, size, CompareByLastAndFirstName);
    printf("\nSorted Records by Last and First Name:\n");
    printRecords(contacts, indexes1, size);
	
	for (int i = 0; i < size; i++){
		printf("%d ", indexes1[i]);
	}
	printf("\n");
	
	InsertSortAge(contacts, indexes2, size);
	printf("\nSorted Records by age:\n");
	printRecords(contacts, indexes2, size);
	
	for (int i = 0; i < size; i++){
		printf("%d ", indexes2[i]);
	}
	printf("\n\n");
	
	int m = BSearchAge(contacts, indexes2, size, X);
	while(contacts[indexes2[m]].age == X){
		if (m != -1){
			printf("Found record by age: Name: %s %s, Phone: %s, Age: %d\n", contacts[indexes2[m]].firstName, contacts[indexes2[m]].lastName, contacts[indexes2[m]].phoneNumber, contacts[indexes2[m]].age);
			m++;
		} 
		else {
			printf("Record with age %d not found\n", X);
		}
	}
	m = BSearchLastName(contacts, indexes1, size, lastname);
	while (strcmp(contacts[indexes1[m]].lastName, lastname) == 0){
		if (m != -1){
			printf("Found record by lastname: Name: %s %s, Phone: %s, Age: %d\n", contacts[indexes1[m]].firstName, contacts[indexes1[m]].lastName, contacts[indexes1[m]].phoneNumber, contacts[indexes1[m]].age);
			m++;
		}
		else {
			printf("Record with lastname '%s' not found\n", lastname);
		}
	}
	return 0;
}
