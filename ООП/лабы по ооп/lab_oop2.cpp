#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int** genMatrix(int size) {
    int **matrix = new int* [size];
    for (int i = 0; i < size; i++){ 
        matrix[i] = new int [size];  
        for (int j = 0; j < size; j++) { 
            matrix[i][j] = rand() % 10; 
        } 
    } 
    return matrix;
}


void spiralFromCenter(int** matrix, int* D, int size) {
    int center = size / 2;
    int index = 0;
    int step = 0;
    while (step <= center) {
        int startRow = center - step;
        int endRow = center + step;
        int startCol = center - step;
        int endCol = center + step;

        for (int i = startCol; i <= endCol; i++) {
            D[index] = matrix[startRow][i];
            index++;
        }
        for (int i = startRow + 1; i <= endRow; i++) {
            D[index] = matrix[i][endCol];
            index++;
        }
        for (int i = endCol - 1; i >= startCol; i--) {
            D[index] = matrix[endRow][i];
            index++;
        }
        for (int i = endRow - 1; i > startRow; i--) {
            D[index] = matrix[i][startCol];
            index++;
        }
        step++;
    }
} 


void spiralFromLeft(int** matrix, int *D, int size) {
    int startCol = 0, endCol = size - 1;
    int startRow = 0, endRow = size - 1;
    int index = 0;

    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; i++) {
            D[index] = matrix[startRow][i]; 
            index++;
        }
        startRow++;
        for (int i = startRow; i <= endRow; i++) {
            D[index] = matrix[i][endCol];
            index++;
        }
        endCol--;
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                D[index] = matrix[endRow][i];
                index++;
            }
            endRow--;
        }
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                D[index] = matrix[i][startCol];
                index++;
            }
            startCol++;
        }
    }
}



void printMatrix(int** matrix, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printArray(int* D, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int N;
    printf("N = ");
    scanf("%d", &N);
    
    int** matrix = genMatrix(N);
    int D[N * N];
    
    printMatrix(matrix, N);

    printf("in a spiral, starting from the central element:\n");
    spiralFromCenter(matrix, D, N);
    printArray(D, N * N);

    printf("in a spiral, starting from the top left element:\n");
    spiralFromLeft(matrix, D, N);
    printArray(D, N * N);    


    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}