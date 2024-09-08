#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
int* genRandArray(int size, int maxValue) { 
    int *arr; 
    arr = new int[size + 1]; 
    arr[0] = size; 
    for (int i = 1; i <= size; i++) { 
        arr[i] = rand() % maxValue; 
    } 
    return arr; 
} 
 
void print(int* arr) { 
    printf("%d: ", arr[0]); 
    for (int i = 1; i <= arr[0]; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
 
int** genRandMatrix(int size, int maxValue) { 
    int **matrix = new int* [size]; 
    for (int i = 0; i < size; i++){ 
        int col = rand() % 10 + 1; 
        matrix[i] = new int [col + 1]; 
        matrix[i][0] = col; 
        for (int j = 1; j <= col; j++) { 
            matrix[i][j] = rand() % maxValue; 
        } 
    } 
    return matrix; 
} 
 
void printMatrix(int ** matrix,  int size) { 
    for (int i = 0; i < size; i++) { 
        print(matrix[i]); 
    } 
} 
 
 
int main() { 
    srand(time(NULL)); 
    int  size = rand() % 10; 
    int maxValue = 100; 
    int* arr = genRandArray(size, maxValue); 
    print(arr); 
    printf("\n"); 

    size = rand() % 10;   
    int** matrix = genRandMatrix(size, maxValue);
    printf("%d\n", size); 
    printMatrix(matrix, size); 
    
    for (int i = 0; i < size; i++){ 
        delete[] matrix[i]; 
    } 
    delete[] matrix;
    delete[] arr; 
    return 0; 
}
