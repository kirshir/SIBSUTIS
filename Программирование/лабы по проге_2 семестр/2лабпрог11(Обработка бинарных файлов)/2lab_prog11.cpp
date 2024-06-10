#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct passenger {
	char lastname[16];
	char firstname[16];
	char fathername[16];
	int baggage;
	float weight;
};

void newPassengers(char* filename, int *N) {
	FILE *file = fopen(filename, "wb");
	if (file == NULL) {
		printf("Error opening file\n");
		return;
	}
	struct passenger passengers[] {
		{"Shirokov", "Kirill", "Vitalevich", 2, 15.6},
		{"Gromova", "Anastasiya", "Evgenevna", 1, 20.1},
		{"Ivanov", "Ivan", "Ivanovich", 3, 9.5},
		{"Agalakov", "Anton", "Alexandrovich", 2, 18.4},
		{"Avdeev", "Egor", "Igorovich", 3, 11.3}
	};
	*N = sizeof(passengers) / sizeof(struct passenger); 
	fwrite(passengers, sizeof(struct passenger), *N, file);
	fclose(file);
}

void printPassengers(char* filename, int N){
	FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    struct passenger passengers[N];
    fread(passengers, sizeof(struct passenger), N, file);
    
    for (int i = 0; i < N; i++) {
        printf("\nPassenger %d:\n", i + 1);
        printf("Lastname: %s\n", passengers[i].lastname);
        printf("Firstname: %s\n", passengers[i].firstname);
        printf("Fathername: %s\n", passengers[i].fathername);
        printf("Baggage: %d\n", passengers[i].baggage);
        printf("Weight: %.1f\n\n", passengers[i].weight);
    }
    fclose(file);
}

void addPassenger(char* filename, int* N) {
	FILE *file = fopen(filename, "ab");
	if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    struct passenger newPassenger;
    printf("Add Passenger\n");
    char ch;
	do {
		printf("Lastname: ");
		scanf("%s", newPassenger.lastname);
		printf("Firstname: ");
		scanf("%s", newPassenger.firstname);
		printf("Fathername: ");
		scanf("%s", newPassenger.fathername);
		printf("Baggage: ");
		scanf("%d", &newPassenger.baggage);
		printf("Weight: ");
		scanf("%f", &newPassenger.weight);
		fwrite(&newPassenger, sizeof(struct passenger), 1, file);
		(*N)++;
		printf("End adding? y/n ");
		getchar();
		scanf("%c", &ch);
	} while (ch != 'y');
	printf("\n");	
	fclose(file);
}

void deletePassanger(char* filename, int* N) {
	FILE *file = fopen(filename, "rb");
	if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    FILE *tempfile = fopen("tempfile.bin", "wb");
	if (tempfile == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    struct passenger temp;
    int deleted = 0;
    for (int i = 0; i < *N; i++) {
    	fread(&temp, sizeof(struct passenger), 1, file);
    	if (temp.weight < 10.0){
    		deleted++;
		}
		else {
			fwrite(&temp, sizeof(struct passenger), 1, tempfile);
		}
	}
	*N -= deleted;
	
	fclose(file);
	fclose(tempfile);
	
	remove(filename);
	rename("tempfile.bin", filename);
} 

void changeWeigh(char *filename, int N) {
	FILE *file = fopen(filename, "rb");
	if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    FILE *tempfile = fopen("tempfile.bin", "wb");
	if (tempfile == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    char changed[16];
    printf("Whose weight to change: ");
    scanf("%s", changed);
    float newWeight;
    printf("Enter new weight: ");
    scanf("%f", &newWeight);
    
    struct passenger passengers[N];
    fread(passengers, sizeof(struct passenger), N, file);
    fclose(file);
    
    for (int i = 0; i < N; i++){
    	if (strcmp(passengers[i].lastname, changed) == 0) {
    		passengers[i].weight = newWeight;
			break;
		}
	}
	fwrite(passengers, sizeof(struct passenger), N, tempfile);
	fclose(tempfile);
	
	remove(filename);
	rename("tempfile.bin", filename);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	int i;
	newPassengers("passengers.bin", &N);
	char ch = 'n';
	while (ch != 'y') {
		printf("1)Посмотреть файл\n");
		printf("2)Добавить в конец файла новую запись\n");
		printf("3)Найти и удалить из файла записи о пассажирах, общий вес которых меньше 10кг\n");
		printf("4)Изменить вес вещей пассажира по заданной фамилии\n");
		printf("Что сделать: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printPassengers("passengers.bin", N);
				break;
			case 2:
				addPassenger("passengers.bin", &N);
				printPassengers("passengers.bin", N);
				break;
			case 3:
				deletePassanger("passengers.bin", &N);
				printPassengers("passengers.bin", N);			
				break;
			case 4:
				changeWeigh("passengers.bin", N);
				printPassengers("passengers.bin", N);
				break;
			default:
				printf("Невозможно сделать\n");
				break;
		}
		
		printf("End? y/n ");
		getchar();
		scanf("%c", &ch);
	}
	return 0;
}
