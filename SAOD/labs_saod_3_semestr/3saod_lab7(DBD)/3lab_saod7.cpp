#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

int levelsCount = 0;

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
            if (rost == true) {  
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
            if (rost == true) { 
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

bool addDBD(Vertex *&p, int data, bool &HR, bool &VR) {
    if (p == NULL) {
        p = new Vertex;
        p->data = data;
        p->balance = 0;
        p->L = NULL;
        p->R = NULL;
        VR = true;
    } else if (p->data > data) {
        if (addDBD(p->L, data, HR, VR)) {
            if (VR) {
                if (p->balance == 0) {
                    Vertex* q = p->L;
                    p->L = q->R;
                    q->R = p;
                    p = q;
                    q->balance = 1;
                    VR = false;
                    HR = true;
                } else {
                    p->balance = 0;
                    VR = true;
                    HR = false;
                }
            } else {
                HR = false;
            }
        } else {
            return false;
        }
    } else if (p->data < data) {
        if (addDBD(p->R, data, HR, VR)) {
            if (VR) {
                p->balance = 1;
                HR = true;
                VR = false;
            } else if (HR) {
                if (p->balance == 1) {
                    Vertex* q = p->R;
                    p->balance = 0;
                    q->balance = 0;
                    p->R = q->L;
                    q->L = p;
                    p = q;
                    VR = true;
                    HR = false;
                } else {
                    HR = false;
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


Vertex* createDBD(int A[], int n, bool &HR, bool &VR) {
    Vertex* root = NULL;
    for (int i = 0; i < n; i++) {
        if (!addDBD(root, A[i], HR, VR)) {
            printf("Element %d already in tree\n", A[i]);
        }
        if (VR) {
            levelsCount++;
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

    bool HR = true;
    bool VR = true;
    Vertex* root1 = createDBD(A, n, HR, VR);
    int root1_size = size(root1);
    int root1_sum = sum(root1);
    int root1_height = height(root1);
    float root1_sOl = (float)sumOfLengths(root1, 1) / (float)size(root1);
    ObhodLeftRight(root1);
    printf("\nCount of levels = %d", levelsCount);

    Vertex* root2 = createAVL(A, n);
    int root2_size = size(root2);
    int root2_sum = sum(root2);
    int root2_height = height(root2);
    float root2_sOl = (float)sumOfLengths(root2, 1) / (float)size(root2);

    printf("\n\nn = %d |  Size  |   Sum   |  Height  |  Avr. height\n", n);
    printf("-------------------------------------------------------\n");
    printf("AVL     |   %d  |  %d  |    %d     |    %.2f\n", root2_size, root2_sum, root2_height, root2_sOl);
    printf("-------------------------------------------------------\n");
    printf("DBD     |   %d  |  %d  |    %d     |    %.2f\n\n", root1_size, root1_sum, root1_height, root1_sOl);

    freeTree(root1);
    freeTree(root2);
    return 0;
}