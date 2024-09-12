// Сформировать с помощью датчика случайных чисел в диапазоне  
// [0,20] два массива C и D, из 20 элементов целого типа каждый. Вывести их на экран.
// Отсортировать массивы C и D по возрастанию и объединить их в массив E, таким образом, чтобы он также оказался отсортирован 
// (добиться сортировки массива Е алгоритмом объединения, заново массив Е не сортировать!) 

#include <stdio.h>
#include <stdlib.h>

const int N=20;
int random(int N) {return rand()% N;}

int main(){
    int C[N], D[N], a=0, b=20;
    int E[N+N];
    for (int i = 0; i<N; i++) {
        C[i] = random(b-a+1)+a;
        printf("%d ", C[i]);
	}
    printf("\n");
    
    for (int i = 0; i<N; i++) {
        D[i] = random(b-a+1)+a;
        printf("%d ", D[i]);
    } 
    printf("\n");
    
    for (int i=0; i<20-1; i++){
		for (int j=20-2; j>=i; j--) {
			if (C[j] > C[j+1]) {
				int temp = C[j];
				C[j] = C[j+1];
				C[j+1] = temp;
			}
		}
	}
	for (int i=0; i<20; i++) {
		printf("%d ", C[i]);
	}
	printf("\n");
	
	for (int i=0; i<20-1; i++){
		for (int j=20-2; j>=i; j--) {
			if (D[j] > D[j+1]) {
				int temp = D[j];
				D[j] = D[j+1];
				D[j+1] = temp;
			}
		}
	}
	
	for (int i=0; i<20; i++) {   
		printf("%d ", D[i]);
	}
	printf("\n");
 
    int i = 0, j = 0, k = 0; 
    while (i < 20 && j < 20) {
        if (C[i] <= D[j]) {
            E[k++] = C[i++];
        } else {
            E[k++] = D[j++];
        }
    }
    while (i < 20) {
        E[k++] = C[i++];
    }
    while (j < 20) {
        E[k++] = D[j++];
    }

    for (int k=0; k<2*N; k++) {
        printf("%d ", E[k]);
    }
    
return 0;
}

