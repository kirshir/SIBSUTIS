#include <stdio.h>
#include <string.h>

struct Record {
	char firstName[30];
    char lastName[30];
    char phoneNumber[15];
    int age;
};

void InsertSort(struct Record arr[], int n, int (*Compare)(struct Record*, struct Record*)) {
	for (int i = 1; i < n; i++) {
	    struct Record key = arr[i];
	    int j = i - 1;
	    while (j >= 0 && Compare(&arr[j], &key) > 0) {
	      arr[j + 1] = arr[j]; 
	      j = j - 1; 
	    }
	    arr[j + 1] = key; 
  	}
}

int CompareByLastAndFirstName(struct Record* a, struct Record* b) {
	int result = strcmp(a->lastName, b->lastName);
    if (result == 0) {
      result = strcmp(a->firstName, b->firstName);
    }
    return result;
}

int compareByAge(struct Record* a, struct Record* b) {
    return (a->age - b->age);
}

void printRecords(struct Record contacts[], int n) {
    for (int i = 0; i < n; i++) {
    	printf("Name: %s %s, Phone: %s, Age: %d\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber, contacts[i].age);
    }
}

int main() {
	struct Record contacts[] = {
	    {"Nastya", "Gromova", "9513984375", 19},
	    {"Kirill", "Shirokov", "9513791855", 18},
	    {"Veronika", "Spasskaya", "9966362469", 19},
	    {"Kate", "Shirikova", "4568952352", 17},
	    {"Ilya", "Ivanov", "9876543256", 20}
	};

  	int n = 5;
  
	printf("Original Records:\n");
    printRecords(contacts, n);

    InsertSort(contacts, n, CompareByLastAndFirstName);
    printf("\nSorted Records by Last and First Name:\n");
    printRecords(contacts, n);
    
    InsertSort(contacts, n, compareByAge);
    printf("\nSorted Records by Age:\n");
    printRecords(contacts, n);

  	return 0;
}

