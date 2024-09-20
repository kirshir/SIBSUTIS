#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

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

// int alreadyIn(int A[], int size, int num) {
//     for (int i = 0; i < size; i++) {
//         if (A[i] == num) {
//             return 1;
//         }
//     }
//     return 0;
// }

// void FillRand(int A[], int n) {
//     int num = 0;
//     int i = 0;
//     while (i < n) {
//         num = rand() % (3 * n);
//         if (!alreadyIn(A, i, num)) {
//             A[i] = num;
//             i++;
//         }
//     }
// }


void FillRand(int A[],int n){
	for(int i = 0; i < n; i++){
		A[i] = rand() % (3 * n);
	}
}

void QuickSort(int L, int R, int A[]) {
	while (L < R) {
		int x = A[L];
		int i = L;
		int j = R;
		while(i <= j) {
			while (A[i] < x) {
				i++;
			}
			while (A[j] > x) {
				j--;
			}
			if (i <= j) {
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i++;
				j--;
	 		}
		}
		
		if ((j - L) < (R - i)) {
			QuickSort(L, j, A);
			L = i;
		}
		else {
			QuickSort(i, R, A);
			R = j;
		}
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

bool addSDP_DI(Vertex *&root, int data) {
    Vertex **p = &root;
    while(*p != NULL) {
        if (data < (*p)->data) {
            p = &((*p)->L);
        }
        else if (data > (*p)->data) {
            p = &((*p)->R);
        } else {
            return false;
        }
    }
    
    if (*p == NULL) {
        *p = new Vertex;
        (*p)->data = data;
        (*p)->L = NULL;
        (*p)->R = NULL;
    }
    return true;
}


Vertex* createSDP_DI(int A[], int n) {
    Vertex* root = NULL;
    for (int i = 0; i < n; i++) {
        if (!addSDP_DI(root, A[i])) {
            printf("Element %d already in tree\n", A[i]);
        } 
    }
    return root;
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

    printf("SDP_DI:\n");
    Vertex* root1 = createSDP_DI(A, n);
    int root1_size = size(root1);
    int root1_sum = sum(root1);
    int root1_height = height(root1);
    float root1_sOl = (float)sumOfLengths(root1, 1) / (float)size(root1);
    ObhodLeftRight(root1);

    printf("\nSDP_R:\n");
    Vertex* root2 = createSDP_R(A, n);
    int root2_size = size(root2);
    int root2_sum = sum(root2);
    int root2_height = height(root2);
    float root2_sOl = (float)sumOfLengths(root2, 1) / (float)size(root2);
    ObhodLeftRight(root2);

    QuickSort(0, n - 1, A);
    Vertex* root3 = ISDP(0, n - 1, A);
    int root3_size = size(root3);
    int root3_sum = sum(root3);
    int root3_height = height(root3);
    float root3_sOl = (float)sumOfLengths(root3, 1) / (float)size(root3);

    printf("\n\nn = 100 |  Size  |   Sum   |  Height  |  Avr. height\n");     
    printf("-------------------------------------------------------\n");
    printf("ISDP    |   %d  |  %d  |    %d     |    %.2f\n", root3_size, root3_sum, root3_height, root3_sOl);
    printf("-------------------------------------------------------\n");
    printf("SDP_DI  |   %d   |  %d  |    %d    |    %.2f\n", root1_size, root1_sum, root1_height, root1_sOl);
    printf("-------------------------------------------------------\n");
    printf("SDP_R   |   %d   |  %d  |    %d    |    %.2f\n\n", root2_size, root2_sum, root2_height, root2_sOl);

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}