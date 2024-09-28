#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vertex {
    int data;
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

bool addSDP_R(Vertex *&root, int data) {
    bool check = true;
    if (root == NULL) {
        root = new Vertex;
        root->data = data;
        root->L = NULL;
        root->R = NULL;
    }
    else if (data < root->data) {
        check = addSDP_R(root->L, data);
    }
    else if (data > root->data) {
        check = addSDP_R(root->R, data);
    } else {
        check = false;
    }
    
    return check;
}

Vertex* createSDP_R(int A[], int n) {
    Vertex* root = NULL;
    for (int i = 0; i < n; i++) {
        if (!addSDP_R(root, A[i])) {
            printf("Element %d already in tree\n", A[i]);
        }
    }
    return root;
}

bool deleteVertex(Vertex *&root, int key) {
    Vertex **p = &root;
    while (*p != NULL) {       //поиск элемента
        if (key < (*p)->data) {
            p = &((*p)->L);
        } else if (key > (*p)->data) {
            p = &((*p)->R);
        } else {
            break;
        }
    } 
    if (*p != NULL) {
        Vertex *q = *p;
        if (q->L == NULL) {
            *p = q->R;
        } else if (q->R == NULL) {
            *p = q->L;
        } else {          //два поддерева 
            Vertex *r = q->L;
            Vertex *s = q;
            if (r->R == NULL) {
                r->R = q->R;
                *p = r;
            } else {
                while (r->R != NULL) {
                    s = r;
                    r = r->R;
                }
                s->R = r->L;
                r->L = q->L;
                r->R  = q->R;
                *p = r;
            }
        }
        delete(q);
    } else {
        return false;
    }
    return true;
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
    int n = 15;
    int A[n];
    FillRand(A, n);

    Vertex* root = createSDP_R(A, n);
    ObhodLeftRight(root);

    int i = 0;
    while (i < 10) {
        int key;
        printf("\nElement to be removed: ");
        scanf("%d", &key);
        if (deleteVertex(root, key)) {
            printf("Element %d removed from tree\n", key);
            ObhodLeftRight(root);
            i++;
        } else {
            printf("Element %d not in tree\n", key);
        }
    }

    freeTree(root);
    return 0;
}