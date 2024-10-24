#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rotateCountAdd = 0;
int rotateCountDelete = 0;

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
                    rotateCountAdd++;
                    rost = false;
                } else {
                    rotateLR(p);
                    rotateCountAdd++;
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
                    rotateCountAdd++;
                    rost = false;
                } else {
                    rotateRL(p);
                    rotateCountAdd++;
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

void rotateRR1(Vertex *&p, bool &decreased) {
    Vertex* q = p->R;
    if (q->balance == 0) {
        q->balance = -1;
        p->balance = 1;
        decreased = false;
    } else {
        q->balance = 0;
        p->balance = 0;
    }

    p->R = q->L;
    q->L = p;
    p = q;
}

void rotateLL1(Vertex *&p, bool &decreased) {
    Vertex *q = p->L;
    if (q->balance == 0) {
        q->balance = 1;
        p->balance = -1;
        decreased = false;
    } else {
        q->balance = 0;
        p->balance = 0;
    }
    
    p->L = q->R;
    q->R = p;
    p = q;
}

void BL(Vertex *&p, bool &decreased) {
    if (p->balance == -1) {
        p->balance = 0;
    }
    else if (p->balance == 0) {
        p->balance = 1;
        decreased = false;
    }
    else if (p->balance == 1) {
        if (p->R->balance >= 0) {
            rotateRR1(p, decreased);
            rotateCountDelete++;
        } else {
            rotateRL(p);
            rotateCountDelete++;
        }
    }
}

void BR(Vertex *&p, bool &decreased) {
    if (p->balance == 1) {
        p->balance = 0;
    }
    else if (p->balance == 0) {
        p->balance = -1;
        decreased = false;
    }
    else if (p->balance == -1) {
        if (p->L->balance <= 0) {
            rotateLL1(p, decreased);
            rotateCountDelete++;
        } else {
            rotateLR(p);
            rotateCountDelete++;
        }
    }
}

void del(Vertex *&r, Vertex *&q, bool &decreased) {
    if (r->R != NULL) {
        del(r->R, q, decreased);
        if (decreased) {
            BR(r, decreased);
        }
    } else {
        q->data = r->data;
        q = r;
        r = r->L;
        decreased = true;
    }
}

bool deleteFromAVL(Vertex *&p, int key, bool &decreased) {
    Vertex *q = NULL;
    if (p == NULL) {
        return false;
    }
    else if (key < p->data) {
        if (!deleteFromAVL(p->L, key, decreased)) {
            return false;
        }
        if (decreased) {
            BL(p, decreased);
        } 
    }
    else if (key > p->data) {
        if (!deleteFromAVL(p->R, key, decreased)) {
            return false;
        }
        if (decreased) {
            BR(p, decreased);
        }
    } else {
        q = p;
        if (q->L == NULL) {
            p = q->R;
            decreased = true;
        } 
        else if (q->R == NULL) {
            p = q->L;
            decreased = true;
        } else {
            del(q->L, q, decreased);
            if (decreased) {
                BL(p, decreased);
            }
        }
    }
    delete(q);
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
    int rotateAddSum = 0;
    int rotateDeleteSum = 0;
    int i = 0;
    while (i < 10) {
        int n = 10000;
        int A[n];
        FillRand(A, n);
        Vertex* root = createAVL(A, n);
        rotateAddSum += rotateCountAdd;

        bool decreased;
        for (int i = 0; i < n; i++) {
            if (deleteFromAVL(root, A[i], decreased)) {
                rotateDeleteSum += rotateCountDelete;
                rotateCountDelete = 0;
            } else {
                printf("Error during deletion!\n");
                return 0;
            }
        }
        rotateCountAdd = 0;
        rotateCountDelete = 0;
        freeTree(root);
        i++;
    }

    float procentAdd = (float)rotateAddSum / 1000;
    float procentDelete = (float)rotateDeleteSum / 1000;
    printf("\nn = 10000 | sum of turns |  procent of turns\n");
    printf("----------------------------------------------\n");
    printf(" Adding   |     %d    |      %.1f%%      \n", rotateAddSum, procentAdd);
    printf("----------------------------------------------\n");
    printf("Deleting  |     %d    |      %.1f%%      \n\n", rotateDeleteSum, procentDelete); 
    return 0;
}