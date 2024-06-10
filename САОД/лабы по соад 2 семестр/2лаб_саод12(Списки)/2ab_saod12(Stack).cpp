#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int Data;
    struct Stack *next;
} Stack;

void push(Stack **head, int Data) {
    Stack *p = (Stack *)malloc(sizeof(Stack));
    if (p == NULL) {
        printf("Error!\n");
    }
    p->Data = Data;
    p->next = *head;
    *head = p;
}

int clean(Stack **head) {
    if (*head == NULL) {
        printf("Stack is empty.");
        return -1;
    }
    int Data = (*head)->Data;
    Stack *p = *head;
    *head = (*head)->next;
    free(p);
    return Data;
}

void print_Stack(Stack *head) {
    Stack *p = head;
    while (p) {
        printf("%d ", p->Data);
        p = p->next;
    }
}

void FillInk(Stack **head) {
    for (int i = 10; i >= 0; i--) {
        push(head, i);
    }
}

void FillDec(Stack **head) {
    for (int i = 0; i <= 10; i++) {
        push(head, i);
    }
}

void FillRand(Stack **head) {
    for (int i = 0; i <= 10; i++) {
        push(head, rand() % (2 * 10));
    }
}

int CheckSum(Stack *head) {
    if (head == NULL)
        return 0;

    int sum = 0;
    Stack *p = head;
    while (p) {
        sum += p->Data;
        p = p->next;
    }
    return sum;
}

int RunNumber(Stack *head) {
    if (head == NULL)
        return 0;

	int ser = 1;
    Stack *p = head;
    Stack *nextNode = head->next;
    while (nextNode != NULL) {
        if(p->Data >= nextNode->Data) {
            ser++;
        }
        p = nextNode;
        nextNode = nextNode->next;
    }
	return ser;
}

void printForward(Stack *head) {
    if (head == NULL)
        return;

    printf("%d ", head->Data);
    printForward(head->next);
}

void printReverse(Stack *head) {
    if (head == NULL)
        return;

    printReverse(head->next);
    printf("%d ", head->Data);
}

int main() {
    Stack *head = NULL;

    FillInk(&head);
    printf("Stack: ");
    print_Stack(head);
    printf("\n");
    printf("CheckSum: %d\n", CheckSum(head));
    printf("RunNumber: %d\n", RunNumber(head));

    printf("Print in Forward Order: ");
    printForward(head);
    printf("\n");
    printf("Print in Reverse Order: ");
    printReverse(head);
    printf("\n\n");

    while (head != NULL) {
        clean(&head);
    }
    
    FillDec(&head);
    printf("Stack: ");
    print_Stack(head);
    printf("\n");
    printf("CheckSum: %d\n", CheckSum(head));
    printf("RunNumber: %d\n", RunNumber(head));

    printf("Print in Forward Order: ");
    printForward(head);
    printf("\n");
    printf("Print in Reverse Order: ");
    printReverse(head);
    printf("\n\n");

    while (head != NULL) {
        clean(&head);
    }

    FillRand(&head);
    printf("Stack: ");
    print_Stack(head);
    printf("\n");
    printf("CheckSum: %d\n", CheckSum(head));
    printf("RunNumber: %d\n", RunNumber(head));

    printf("Print in Forward Order: ");
	printForward(head);
    printf("\n");
    printf("Print in Reverse Order: ");
    printReverse(head);
    printf("\n\n");

    while (head != NULL) {
        clean(&head);
    }
    
    return 0;
}
