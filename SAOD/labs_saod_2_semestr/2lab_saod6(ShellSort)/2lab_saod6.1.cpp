#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int M = 0;
int C = 0;

void FillRand(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % (2 * n);
    }
}

void Knut(int n, int *h) {
    int m = log2(n) - 1;
    h[0] = 1;
    for (int i = 1; i < m; i++) {
        h[i] = 2 * h[i - 1] + 1;
    }
}

void ShellSort(int A[], int n, int h[]) {
    int m = log2(n) - 1;
    for (int k = m - 1; k >= 0; k--) {
        for (int i = h[k]; i < n; i++) {
            int t = A[i];
            int j = i - h[k];
            M++;
            int f = 0;
            while (j >= 0 && t < A[j]) {
                C++;
                A[j + h[k]] = A[j];
                M++;
                j = j - h[k];
                f = 1;
            }
            if (f == 0) {
                C++;
            }
            A[j + h[k]] = t;
            M++;
        }
    }
}

void Sedgewick(int n, int *h1, int *size) {
    int k = 0;
    while (1) {
        int t;
        if (k % 2 == 0) {
            t = 9 * (pow(2, k) - pow(2, k / 2)) + 1;
        } else {
            t = 8 * pow(2, k) - 6 * pow(2, (k + 1) / 2) + 1;
        }

        if (t >= n) {
			break;
		}

        h1[*size] = t;
        (*size)++;

        k++;
    }
}

void ShellSort2(int A[], int n, int h1[], int size) {
    for (int k = size - 1; k >= 0; k--) {
        for (int i = h1[k]; i < n; i++) {
            int t = A[i];
            int j = i - h1[k];
            M++;
            int f = 0;
            while (j >= 0 && t < A[j]) {
                C++;
                A[j + h1[k]] = A[j];
                M++;
                j = j - h1[k];
                f = 1;
            }
            if (f == 0) {
                C++;
            }
            A[j + h1[k]] = t;
            M++;
        }
    }
}

int main() {
	printf("n\th1...hm(Knut)\t\tShell(M+C) \th1...hm(Sedgewick)  \t\tShell(M+C)\n");
    for (int i = 100; i <= 500; i += 100) {
        int n = i;
        int A[n];
        int m = log2(n) - 1;
        int h[m - 1];
        Knut(n, h);
        FillRand(A, n);
        ShellSort(A, n, h);
        int Sum_Shell = M + C;
        M = 0;
        C = 0;
		int h_size = sizeof(h) / sizeof(h[0]);
		char h_str[h_size * 2];
		int offset = 0;
		for (int i = 0; i <= h_size; i++){
			int written = sprintf(h_str + offset, "%d", h[i]);
			offset += written;
			if (i <= h_size - 1){
				h_str[offset++] = ',';
			}
		}
		h_str[offset] = '\0';


        int max_size = 50;
        int *h1 = (int *)malloc(max_size * sizeof(int));
        if (h1 == NULL) {
            printf("Error memory\n");
            return 1;
        }
        int size = 0;

        Sedgewick(n, h1, &size);
        FillRand(A, n);
        ShellSort2(A, n, h1, size);
        int Sum_Shell2 = M + C;
        M = 0;
        C = 0;
        int h1_size = size;
		char h1_str[h1_size * 3];
		int offset2 = 0;
		for (int i = 0; i < h1_size; i++){
			int written2 = sprintf(h1_str + offset2, "%d", h1[i]);
			offset2 += written2;
			if (i < h1_size - 1){
				h1_str[offset2++] = ',';
			}
		}
		h1_str[offset2] = '\0';
        

        printf("%d\t%s\t\t%d\t\t%s\t\t\t%d\n", n, h_str, Sum_Shell, h1_str, Sum_Shell2);

        free(h1);
    }

    return 0;
}

