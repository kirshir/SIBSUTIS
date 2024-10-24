#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) { 
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
} 

int** genRandMatrix(int size) { 
    int **matrix = new int* [size]; 
    for (int i = 0; i < size; i++){ 
        int col = rand() % 10 + 1; 
        matrix[i] = new int [col]; 
        for (int j = 0; j < col; j++) { 
            matrix[i][j] = rand() % 10 + 1; 
        } 
        print(matrix[i], col);
    } 
    return matrix; 
}

int main() {
    srand(time(NULL));
    int  size = rand() % 10; 
    int** matrix = genRandMatrix(size);
    
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
