#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

struct Vertex {
    int data;
    Vertex* L;
    Vertex* R;
};

void FillInc(int A[], int n){
	for(int i = 0; i < n; i++){
		A[i] = i;
	}
}

Vertex* createBranch() {
    Vertex* p = (Vertex* )malloc(sizeof(Vertex));
    if (p == NULL) {
        printf("Memory Error!\n");
        exit(1);
    }
    p->L = NULL;
    p->R = NULL;
    return p;
}

Vertex* ISDP(int L, int R, int A[]) {
    if (L > R) return NULL;
    else {
        int m = (L + R + 1) / 2;
        Vertex* p = createBranch();
        p->data = A[m];
        p->L = ISDP(L, m - 1, A);
        p->R = ISDP(m + 1, R, A);
        return p;
    }
}

void ObhodLeftRight(Vertex* root) {
    if (root != NULL) {
        ObhodLeftRight(root->L);
        printf("%d ", root->data);
        ObhodLeftRight(root->R);
    }
}

int size(Vertex* root) {
    int n = 0;
    if (root == NULL) {
        return 0;
    } else {
        n = 1 + size(root->L) + size(root->R);
    }
    return n;
}

int sum(Vertex* root) {
    int s = 0;
    if (root == NULL) {
        return 0;
    } else {
        s = root->data + sum(root->L) + sum(root->R);
    }
    return s;
}

int height(Vertex* root) {
    int h = 0;
    if (root == NULL) {
        return 0;
    }
    else {
        h = 1 + std::max(height(root->L), height(root->R));
    }
    return h;
}

int sumOfLengths(Vertex* root, int L) {
    int s = 0;
    if (root == NULL) {
        return 0;
    } else {
        s = L + sumOfLengths(root->L, L + 1) + sumOfLengths(root->R, L + 1);
    }
    return s;
}

void freeTree(Vertex* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->L);
    freeTree(root->R);
    free(root);
}

int main() {
    int n = 100;
    int A[n];
    FillInc(A, n);
    Vertex* root = ISDP(0, n - 1, A);
    ObhodLeftRight(root);
    
    int n1 = size(root);
    printf("\nРазмер = %d", n1);

    int s = sum(root);
    printf("\nСумма = %d", s);

    int h = height(root);
    printf("\nВысота = %d", h);

    float s1 = (float)sumOfLengths(root, 1) / (float)size(root);
    printf("\nСредняя высота дерева = %.2f", s1);

    freeTree(root);
    return 0;
}