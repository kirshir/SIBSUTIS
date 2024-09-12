//Сформировать с помощью датчика случайных чисел в диапазоне [-10,10] массив из 20 элементов целого типа.
//Вывести его на экран.  Затем вывести на экран  все положительные элементы массива, и все отрицательные элементы.


#include <stdio.h>
#include <stdlib.h>
const int N=20;
int random(int N) {return rand()% N;}
 
int main() {
 	int A[N], a=-10, b=10;
 	for (int i = 0; i<N; i++){
 	 	A[i] = random(b-a+1)+a;
  		printf("%d ", A[i]);}
 	printf("\n");
 	for (int i = 0; i<N; i++)
  		if (A[i]>0) printf("%d ", A[i]); 
 	printf("\n");
 	for (int i=0;i<N;i++)
  		if (A[i]<0) printf("%d ", A[i]);
return 0;
}
