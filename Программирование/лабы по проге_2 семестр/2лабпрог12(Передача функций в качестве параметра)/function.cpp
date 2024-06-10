#include "function.h"
#include <time.h>
#include <stdlib.h>

void FillRandInt(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % (2 * n);
    }
} 

void FillRandFloat(float B[], int n) {
    for (int i = 0; i < n; i++) {
        B[i] = (float)rand() / RAND_MAX * n;
    }
}

double timer(void (*func)(int*, int), int arr[], int n) {
    clock_t start, end;
    double time;

    start = clock();
    func(arr, n); 
    end = clock();

    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

double timer2(void (*func)(float*, int), float arr[], int n) {
    clock_t start, end;
    double time;

    start = clock();
    func(arr, n); 
    end = clock();

    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

void InsertSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int t = A[i];
        int j = i - 1;
        while (j >= 0 && t < A[j]) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = t; 
    }
}

void SelectSort(int A[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        int temp = A[i]; 
        A[i] = A[k]; 
        A[k] = temp; 
    }
}



void InsertSort2(float B[], int n) {
    for (int i = 1; i < n; i++) {
        float t = B[i];
        int j = i - 1;
        while (j >= 0 && t < B[j]) {
            B[j + 1] = B[j];
            j = j - 1;
        }
        B[j + 1] = t; 
    }
}

void SelectSort2(float B[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (B[j] < B[k]) {
                k = j;
            }
        }
        float temp = B[i]; 
        B[i] = B[k]; 
        B[k] = temp; 
    }
}

void BubbleSort(int A[], int n) {
	for (int i = 0; i < (n - 1); i++) {
    	for(int j = 0; j < (n - i - 1); j++) {
      		if(A[j] > A[j + 1]) {
        		int temp = A[j]; 
        		A[j] = A[j + 1]; 
        		A[j + 1] = temp; 
      		}
    	}
  	}
}

void BubbleSort2(float B[], int n) {
	for (int i = 0; i < (n - 1); i++) {
    	for(int j = 0; j < (n - i - 1); j++) {
      		if(B[j] > B[j + 1]) {
        		float temp = B[j]; 
       			B[j] = B[j + 1]; 
        		B[j + 1] = temp; 
      		}
    	}
	}
}

