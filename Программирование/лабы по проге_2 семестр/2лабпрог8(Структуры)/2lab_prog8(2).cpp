#include <stdio.h>
#include <string.h>

struct Rooms {
	int Room_Number;
	float Room_S;
	char faculty[5];
	int Students;
};

int main() {
	int size = 7;
	struct Rooms rooms[size]{
		{45, 20, "IVT", 3},
		{55, 20, "IB", 4},
		{49, 22, "IT", 4},
		{88, 22, "IVT", 3},
		{99, 25, "MTS", 2},
		{5, 20, "IVT", 4},
		{71, 25, "IT", 2}
	};
	char faculties[size][5];
	int fac_num = 0;
	for (int i = 0; i < size; i++){
		int found = 0;
		for (int j = 0; j < fac_num; j++){
			if (strcmp(rooms[i].faculty, faculties[j]) == 0){
				found = 1;
				break;
			}
		}
		if (!found){
			strcpy(faculties[fac_num], rooms[i].faculty);
			fac_num++;
		}
	}
	printf("Different faculties = %d\n\n", fac_num);
    for (int i = 0; i < fac_num; i++) {
	  	printf("Faculties: %s\n", faculties[i]);
		int room_num = 0;
		int stud_num = 0;
		int rooms_S = 0;
		float avg_S = 0;
		for (int j = 0; j < size; j++){
			if (strcmp(rooms[j].faculty, faculties[i]) == 0) {
				room_num++;
				stud_num += rooms[j].Students;
				rooms_S += rooms[j].Room_S;
			}
		}
		avg_S += (float)rooms_S / stud_num;
		printf("Number of rooms = %d\n", room_num);
		printf("Number of students = %d\n", stud_num);
		printf("Average area per student = %.2f\n\n", avg_S);    	
	}
	return 0;
}




