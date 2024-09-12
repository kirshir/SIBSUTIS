//Сформировать с помощью датчика случайных чисел в диапазоне [0,10] массив из 20 элементов вещественного типа.
//Вывести его на экран. Вывести элементы массива, большие своих соседей справа и слева.


#include <stdio.h> 
#include <stdlib.h> 
 
const int N=20; 
int random(int N) {return rand()% N;} 
  
int main()  
{ 
    float A[N]; 
    int a=0, b=10; 
    for (int i = 0; i<N; i++) { 
        A[i] = (float)rand()*(b-a)/RAND_MAX + a;  
        printf("%f ", A[i]); 
 } 
    printf("\n"); 
     
 for (int i = 0; i<N; i++) { 
    if (i > 0 && i < N - 1){ 
        if(A[i] > A[i - 1] && A[i] > A[i + 1]){ 
            printf("%f ", A[i]); } 
        } 
    } 
   
return 0;    
}
