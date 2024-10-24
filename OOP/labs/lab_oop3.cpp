#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Matrix {
    private:
        int x;
        int y;
        int** matr;
        int sum;

    public:
        Matrix() {
            x = 0;
            y = 0;
            matr = new int*[0];
        }

        Matrix(int size) {
            x = size;
            y = size;
            matr =  new int*[size];
            for (int i = 0; i < size; i++) {
                matr[i] = new int[size];
                for (int j = 0; j < size; j++) {
                    if (i == j) {
                        matr[i][j] = 1;
                    } else {
                        matr[i][j] = 0;
                    }
                }
            }
        }

        Matrix(int x1, int y1) {
            x = x1;
            y = y1;
            matr = new int*[x];
            for (int i = 0; i < x; i++) {
                matr[i] = new int[y];
                for (int j = 0; j < y; j++) {
                    matr[i][j] = 0;
                }
            }
        }

        void keyboardInput() {
            int current = 0;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    scanf("%d", &current);
                    matr[i][j] = current;
                }
            }
        }

        void fillRand() {
            srand(time(NULL));
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    matr[i][j] = rand() % 9 + 1;
                }
            }
        }

        void printMatr() {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    printf("%d ", matr[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }

        int sumOfElemets() {
            sum = 0;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    sum += matr[i][j];
                }
            }
            return sum;
        }

        void fillMultiply() {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j ++) {
                    matr[i][j] = (i + 1) * (j + 1);
                }
            }
        }
 
        ~Matrix() {
            for (int i = 0; i < x; i++) {
                delete[] matr[i];
            }
            delete[] matr;
        }
};


int main() {
    Matrix M1;
    Matrix M2(3);
    Matrix M3(3, 4);
    Matrix M4(2, 3);
    printf("M1:\n");
    M1.printMatr();
    printf("M2:\n");
    M2.printMatr();
    printf("M3:\n");
    M3.printMatr();
    printf("M4:\n");
    M4.printMatr();

    printf("\nM2(multiplied):\n");
    M2.fillMultiply();
    M2.printMatr();

    printf("\nM3(random):\n");
    M3.fillRand();
    M3.printMatr();

    printf("\nM4(keyboard input):\n");
    M4.keyboardInput();
    printf("\n");
    M4.printMatr();

    printf("\nM3(sum):\n");
    int sum1 = M3.sumOfElemets();
    printf("sum = %d", sum1);
    return 0;
}