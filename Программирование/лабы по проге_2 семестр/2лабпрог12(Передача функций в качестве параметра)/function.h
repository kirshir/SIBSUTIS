#pragma once

void FillRandInt(int A[], int n);
void FillRandFloat(float B[], int n);
double timer(void (*func)(int*, int), int arr[], int n);
double timer2(void (*func)(float*, int), float arr[], int n);
void InsertSort(int A[], int n);
void SelectSort(int A[], int n);
void BubbleSort(int A[], int n);
void InsertSort2(float B[], int n);
void SelectSort2(float B[], int n);
void BubbleSort2(float B[], int n);

