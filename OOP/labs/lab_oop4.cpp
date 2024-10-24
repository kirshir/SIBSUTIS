#include <stdio.h>

template <typename T>
class Matrix
{
    private:
        int m; //строка
        int n; // столбец
        T **M;
    public:
        Matrix() 
        { 
            m = 0; n = 0;
            M = nullptr;
        }

        Matrix(int m1, int n1) 
        {
            m = m1, n = n1;
            M = new T *[m];
            for (int i = 0; i < m; i++) {
                M[i] = new T [n];
                for (int j = 0; j < n; j++) {
                    M[i][j] = 0;
                }
            }
        }

        Matrix(const Matrix &M1) 
        {
            n = M1.n;
            m = M1.m;
            M = new T *[m];
            for (int i = 0; i < m; i++) {
                M[i] = new T[n];
                for (int j = 0; j < n; j++) {
                    M[i][j] = M1.M[i][j];
                }
            }
        }

        Matrix& operator=(Matrix& M1) 
        {
            if (this == &M1) {
                return *this;
            }
            for (int i = 0; i < m; i++) {
                delete[] M[i];
            }
            delete[] M;

            n = M1.n;
            m = M1.m;

            M = new T*[m];
            for (int i = 0; i < m; i++) {
                M[i] = new T[n];
                for (int j = 0; j < n; j++) {
                    M[i][j] = M1.M[i][j];
                }
            }
            return *this;
        }

        ~Matrix() 
        {
            for(int i = 0; i < m; i++){
                delete[] M[i];
            }
            delete[] M;
        }

        void SetM(int m, int n, T data)
        {
            M[m][n] = data;
        }

        void GetM(int m, int n) 
        {
            printf("%d ", M[m][n]);
        }

        void PrintMatrixInt() 
        {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    printf("%d ", M[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }

        void PrintMatrixDouble() 
        {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    printf("%.1f ", M[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
};

int main() {
    Matrix <int> M(3, 4);
    printf("Object: M\n");
    M.PrintMatrixInt();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            M.SetM(i, j, i + j);
        }
    }
    printf("Object: M\n");
    M.PrintMatrixInt();

    Matrix <int> M1 = M;
    printf("Object: M1\n");
    M1.PrintMatrixInt();

    Matrix <int> M2;
    M2 = M;
    printf("Object: M2\n");
    M2.PrintMatrixInt();

    Matrix <int> M3;
    M3 = M2 = M1 = M;
    printf("Object: M3\n");
    M3.PrintMatrixInt();

    printf("---------------------------------------------------\n");
    Matrix <double> M_d(3, 4);
    printf("Object: M\n");
    M_d.PrintMatrixInt();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            M_d.SetM(i, j, (i + j) * 0.5);
        }
    }
    printf("Object: M\n");
    M_d.PrintMatrixDouble();

    Matrix <double> M_d1 = M_d;
    printf("Object: M1\n");
    M_d1.PrintMatrixDouble();

    Matrix <double> M_d2;
    M_d2 = M_d1;
    printf("Object: M2\n");
    M_d2.PrintMatrixDouble();

    Matrix <double> M_d3;
    M_d3 = M_d2 = M_d1 = M_d;
    printf("Object: M3\n");
    M_d3.PrintMatrixDouble();

    return 0;
}
