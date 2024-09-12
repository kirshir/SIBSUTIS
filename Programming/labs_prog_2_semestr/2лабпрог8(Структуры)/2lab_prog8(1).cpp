#include <stdio.h>

struct School{
	int School_Number;
	int Graduates;
	int Entered; 
};

void sort(struct School school[], int indexes[], int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = i + 1; j < size ; j++){
			float procent1 = ((float)school[indexes[i]].Entered / school[indexes[i]].Graduates) * 100;
			float procent2 = ((float)school[indexes[j]].Entered / school[indexes[j]].Graduates) * 100;
			if (procent1 < procent2){
				int temp = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = temp;
			}
		}
	}
}

int main() {
	int size = 5;
	struct School school[size]= {
		{207, 56, 44}, //78
		{203, 55, 41}, //74
		{211, 60, 39}, //65
		{218, 59, 40}, //67
		{105, 51, 37}  //72
	};
	int indexes[size] = {0, 1, 2, 3, 4};
	sort(school, indexes, size);
	for (int i = 0; i < size; i++){
		printf("School Number = %d:  Graduates = %d,  Procent entered to university = %.2f%%\n",
				school[indexes[i]].School_Number, 
				school[indexes[i]].Graduates, 
				(float)school[indexes[i]].Entered / school[indexes[i]].Graduates * 100);
	}
	return 0;
}
