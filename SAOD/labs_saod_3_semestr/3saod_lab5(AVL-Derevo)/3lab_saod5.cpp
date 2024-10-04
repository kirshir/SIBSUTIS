#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

struct Vertex {
    int data;
    int balance;
    Vertex* L;
    Vertex* R;
};

int alreadyIn(int A[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (A[i] == num) {
            return 1;
        }
    }
    return 0;
}

void FillRand(int A[], int n) {
    int num = 0;
    int i = 0;
    while (i < n) {
        num = rand() % (3 * n);
        if (!alreadyIn(A, i, num)) {
            A[i] = num;
            i++;
        }
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

void rotateLL(Vertex *&p) {
    Vertex *q = p->L;
    p->balance = 0;
    q->balance = 0;
    p->L = q->R;
    q->R = p;
    p = q;
}

void rotateRR(Vertex *&p) {
    Vertex *q = p->R;
    p->balance = 0;
    q->balance = 0;
    p->R = q->L;
    q->L = p;
    p = q;
}

void rotateLR(Vertex *&p) {
    Vertex *q = p->L;
    Vertex *r = q->R;
    if (r->balance < 0) {
        p->balance = 1;
    } else {
        p->balance = 0;
    }

    if (r->balance > 0) {
        q->balance = -1;
    } else {
        q->balance = 0;
    }

    r->balance = 0;
    q->R = r->L;
    p->L = r->R;
    r->L = q;
    r->R = p;
    p = r;
}

void rotateRL(Vertex *&p) {
    Vertex *q = p->R;
    Vertex *r = q->L;
    if (r->balance > 0) {
        p->balance = -1;
    } else {
        p->balance = 0;
    }

    if (r->balance < 0) {
        q->balance = 1;
    } else {
        q->balance = 0;
    }

    r->balance = 0;
    q->L = r->R;
    p->R = r->L;
    r->L = p;
    r->R = q;
    p = r;
}

bool addAVL(Vertex *&p, int data, bool &rost) {
    if (p == NULL) {
        p = new Vertex;
        p->data = data;
        p->balance = 0;
        p->L = NULL;
        p->R = NULL;
        rost = true;
    } else if (p->data > data) {
        if (addAVL(p->L, data, rost)) {
            if (rost == true) {         //выросла левая ветвь
                if (p->balance > 0) {
                    p->balance = 0;
                    rost = false;
                } else if (p->balance == 0) {
                    p->balance = -1;
                    rost = true;
                } else if (p->L->balance < 0) {
                    rotateLL(p);
                    rost = false;
                } else {
                    rotateLR(p);
                    rost = false;
                }
            } 
        } else {
            return false;
        }
    } 
    else if (p->data < data) {
        if (addAVL(p->R, data, rost)) {
            if (rost == true) {          //выросла правая ветвь
                if (p->balance < 0) {
                    p->balance = 0;
                    rost = false;
                } else if (p->balance == 0) {
                    p->balance = 1;
                    rost = true;
                } else if (p->R->balance > 0) {
                    rotateRR(p);
                    rost = false;
                } else {
                    rotateRL(p);
                    rost = false;
                }
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
}


Vertex *createAVL(int A[], int n) {
    Vertex* root = NULL;
    bool rost;
    for (int i = 0; i < n; i++) {
        if (!addAVL(root,  A[i], rost)) {
            printf("Element %d already in tree\n", A[i]);
        }
    }
    return root;
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
    srand(time(NULL));
    int n = 100;
    int A[n];
    FillRand(A, n);

    Vertex *root1 = createAVL(A, n);
    int root1_size = size(root1);
    int root1_sum = sum(root1);
    int root1_height = height(root1);
    float root1_sOl = (float)sumOfLengths(root1, 1) / (float)size(root1);
    ObhodLeftRight(root1);
    
    Vertex* root2 = ISDP(0, n - 1, A);
    int root2_size = size(root2);
    int root2_sum = sum(root2);
    int root2_height = height(root2);
    float root2_sOl = (float)sumOfLengths(root2, 1) / (float)size(root2);

    printf("\n\nn = %d |  Size  |   Sum   |  Height  |  Avr. height\n", n);
    printf("-------------------------------------------------------\n");
    printf("ISDP    |   %d  |  %d  |    %d     |    %.2f\n", root2_size, root2_sum, root2_height, root2_sOl);
    printf("-------------------------------------------------------\n");
    printf("AVL     |   %d  |  %d  |    %d     |    %.2f\n\n", root1_size, root1_sum, root1_height, root1_sOl);

    freeTree(root1);
    freeTree(root2);
    return 0;
}