#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

struct Vertex {
    int data;
    Vertex* L;
    Vertex* R;
};

Vertex* createBranch(int value) {
    Vertex* root = (Vertex* )malloc(sizeof(Vertex));
    if (root == NULL) {
        printf("Memory Error!\n");
        exit(1);
    }
    root->data = value;
    root->L = NULL;
    root->R = NULL;
    return root;
}


Vertex* createTree() {
    Vertex* root = createBranch(1);
    root->L = createBranch(2);
    root->L->R = createBranch(3);
    root->L->R->L = createBranch(4);
    root->L->R->L->R = createBranch(5);
    root->L->R->L->R->R = createBranch(6);
    return root;
}

//Обход сверху вниз
void ObhodUpDown(Vertex* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        ObhodUpDown(root->L);
        ObhodUpDown(root->R);
    }
}

//Обход слева направо
void ObhodLeftRight(Vertex* root) {
    if (root != NULL) {
        ObhodLeftRight(root->L);
        printf("%d ", root->data);
        ObhodLeftRight(root->R);
    }
}


//Обход снизу вверх
void ObhodDownUp(Vertex* root) {
    if (root != NULL) {
        ObhodDownUp(root->L);
        ObhodDownUp(root->R);
        printf("%d ", root->data);
    }
}

void printTree(Vertex* root) {
    if (root == NULL) {
        printf("tree is empty\n");
        exit(1);
    }
    printf("      %d      \n", root->data);
    printf("     /\n");
    printf("    %d\n", root->L->data);
    printf("     \\\n");
    printf("       %d\n", root->L->R->data);
    printf("      /\n");
    printf("     %d\n", root->L->R->L->data);
    printf("      \\\n");
    printf("        %d\n", root->L->R->L->R->data);
    printf("         \\\n");
    printf("          %d\n", root->L->R->L->R->R->data);
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
    Vertex* root = createTree();
    printTree(root);

    printf("\nОбход сверху вниз: ");
    ObhodUpDown(root);

    printf("\nОбход слева на право: ");
    ObhodLeftRight(root);

    printf("\nОбход снизу вверх: ");
    ObhodDownUp(root);

    int n = size(root);
    printf("\nРазмер = %d", n);

    int s = sum(root);
    printf("\nСумма = %d", s);

    int h = height(root);
    printf("\nВысота = %d", h);

    float s1 = sumOfLengths(root, 1) / size(root);
    printf("\nСредняя высота дерева = %.2f", s1);

    freeTree(root);
    return 0;
}
