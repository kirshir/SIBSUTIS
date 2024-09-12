#include <stdio.h>
#include <stdlib.h>

typedef struct Queue { 
    int Data;
    struct Queue *next;
} Queue;

void push(Queue **head, Queue **tail, int Data) {
    Queue *p = (Queue *)malloc(sizeof(Queue));
    if (p == NULL) {
        printf("Error!\n");
    }
    p->Data = Data;
    p->next = NULL;
    if(*tail == NULL) {
        *head = p;
    } else {
        (*tail)->next = p;
    }
    (*tail) = p;
}

int clean(Queue **head, Queue **tail) {
    if (*head == NULL) {
        printf("Queue is empty.");
        return -1;
    }
    int Data = (*head)->Data;
    Queue *p = *head;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(p);
    return Data;
}

void print_Queue(Queue *head) {
    Queue *p = head;
    while (p) {
        printf("%d ", p->Data);
        p = p->next;
    }
}

void FillInk(Queue **head, Queue **tail) {
    for (int i = 1; i <= 10; i++) {
        push(head, tail, i);
    }
}

void FillDec(Queue **head, Queue **tail) {
    for (int i = 10; i >= 0; i--) {
        push(head, tail, i);
    }
}

void FillRand(Queue **head, Queue **tail) {
    for (int i = 0; i <= 10; i++) {
        push(head, tail, rand() % (2 * 10));
    }
}

int CheckSum(Queue *head) {
    if (head == NULL)
        return 0;

    int sum = 0;
    Queue *p = head;
    while (p) {
        sum += p->Data;
        p = p->next;
    }
    return sum;
}

int RunNumber(Queue *head) {
    if (head == NULL)
        return 0;

	int ser = 1;
    Queue *p = head;
    Queue *nextNode = head->next;
    while (nextNode != NULL) {
        if(p->Data >= nextNode->Data) {
            ser++;
        }
        p = nextNode;
        nextNode = nextNode->next;
    }
	return ser;
}

void printForward(Queue *head) {
    if (head == NULL)
        return;

    printf("%d ", head->Data);
    printForward(head->next);
}

void printReverse(Queue *head) {
    if (head == NULL)
        return;

    printReverse(head->next);
    printf("%d ", head->Data);
}

int main() {
    Queue *head = NULL;
    Queue *tail = NULL;

    FillInk(&head, &tail);
    printf("Queue: ");
    print_Queue(head);
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
        clean(&head, &tail);
    }
    
    FillDec(&head, &tail);
    printf("Queue: ");
    print_Queue(head);
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
        clean(&head, &tail);
    }

    FillRand(&head, &tail);
    printf("Queue: ");
    print_Queue(head);
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
        clean(&head, &tail);
    }
    
    return 0;
}
