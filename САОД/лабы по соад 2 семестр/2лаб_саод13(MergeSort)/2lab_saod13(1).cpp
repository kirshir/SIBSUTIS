#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
int M = 0;
int C = 0;

struct Stack {
    Stack *next;
	int data;
};

struct Queue {
	Stack *head;
	Stack *tail;
};

int CheckSumStack(Stack *head) {
    if (head == NULL)
        return 0;

    int sum = 0;
    Stack *p = head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int CheckSumQueue(Queue *queue) {
    if (queue == NULL)
        return 0;

    int sum = 0;
    Stack *p = queue->head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int RunNumberStack(Stack *head) {
    if (head == NULL)
        return 0;

	int ser = 1;
    Stack *p = head;
    Stack *nextNode = head->next;
    while (nextNode != NULL) {
        if(p->data > nextNode->data) {
            ser++;
        }
        p = nextNode;
        nextNode = nextNode->next;
    }
	return ser;
}

int RunNumberQueue(Queue *queue) {
    if (queue == NULL)
        return 0;

	int ser = 1;
    Stack *p = queue->head;
    Stack *nextNode = p->next;
    while (nextNode != NULL) {
        if(p->data > nextNode->data) {
            ser++;
        }
        p = nextNode;
        nextNode = nextNode->next;
    }
	return ser;
}

void StackFillInc(int n, Stack *(&head))
{
    int i = n;
    Stack *p;
    p = NULL;
    do
    {

        head = new Stack;
        head->next = p;
        p = head;
        head->data = i;
        i--;

    } while (i > 0);
}

void StackFillDec(int n, Stack *(&head))
{
    int i = 1;
    Stack *p;
    p = NULL;
    do
    {
        head = new Stack;
        head->next = p;
        p = head;
        head->data = i;
        i++;

    } while (i <= n);
}

void StackFillRand(int n, Stack *(&head))
{
    srand(time(NULL));
    int i = 1;
    Stack *p;
    p = NULL;
    do
    {
        head = new Stack;
        head->next = p;
        p = head;
        head->data = rand() % (n * 2);
        i++;

    } while (i <= n);
}

//void QueueFillInc(int n, Stack *(&head), Stack *(&tail))
//{
//    int i = 1;
//    Stack *p;
//    head = tail = new Stack;
//    head->next = tail->next = 0;
//    tail->data = i;
//    i++;
//    do
//    {
//        p = new Stack;
//        p->data = i;
//        tail->next = p;
//        tail = p;
//        i++;
//
//    } while (i <= n);
//    tail->next = 0;
//}

//void QueueFillDec(int n, Stack *(&head), Stack *(&tail))
//{
//    int i = n;
//    Stack *p;
//    head = tail = new Stack;
//    head->next = tail->next = 0;
//    tail->data = i;
//    i--;
//    do
//    {
//        p = new Stack;
//        p->data = i;
//        tail->next = p;
//        tail = p;
//        i--;
//
//    } while (i > 0);
//    tail->next = 0;
//}

//void QueueFillRand(int n, Stack *(&head), Stack *(&tail))
//{
//    srand(time(NULL));
//    int i = 1;
//    Stack *p;
//    head = tail = new Stack;
//    head->next = tail->next = 0;
//    tail->data = rand() % (n * 2);
//    i++;
//    do
//    {
//        p = new Stack;
//        p->data = rand() % (n * 2);
//        tail->next = p;
//        tail = p;
//        i++;
//
//    } while (i <= n);
//    tail->next = 0;
//}

int cleanStack(Stack **head) {
    if (*head == NULL) {
        printf("Stack is empty.");
        return -1;
    }
    int Data = (*head)->data;
    Stack *p = *head;
    *head = (*head)->next;
    free(p);
    return Data;
}

int cleanQueue(Queue **queue) {
    if ((*queue)->head == NULL) {
        printf("Queue is empty.");
        return -1;
    }
    Stack *p = (*queue)->head;
    (*queue)->head = (*queue)->head->next;
    if ((*queue)->head == NULL) {
        (*queue)->tail = NULL;
    }
    free(p);
    return 0;
}

void printStack(Stack *head) {
    Stack *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}


void printQueue(Queue *queue) {
    Stack *p = queue->head;
    while (p) {
        printf("%d ", p->data); 
        p = p->next;
    }
}

int countElementsStack(Stack *stack) {
	int count = 0;
	Stack *cursor = stack;
	while (cursor != NULL) {
		count++;
		cursor = cursor->next;
	} 
	return count;
}

int countElementsQueue(Queue *queue) {
	int count = 0;
	Stack *cursor = queue->head;
	while (cursor != NULL) {
		count++;
		cursor = cursor->next;
	} 
	return count;
}

int Split(Stack *S, Stack **a, Stack **b) {
	*a = S;
	*b = S->next;
	int n = 1;
	Stack *k = *a;
	Stack *p = *b;
	M += 4;
	while (p != NULL) {
		M += 2;
		n++;
		k->next = p->next;
		k = p;
		p = p->next;
	}
	return n;
}

void Merger(Stack **a, int q, Stack **b, int r, Queue *c) {

    while (q != 0 && r != 0) {
    	C++;
        if ((*a)->data <= (*b)->data) {
        	M++;
            if (c->head == NULL) {
                c->head = *a; 
            } else {
                c->tail->next = *a; 
            }
            c->tail = *a; 
            *a = (*a)->next;
            q--;
        } else {
        	M++;
            if (c->head == NULL) {
                c->head = *b; 
            } else {
                c->tail->next = *b; 
            }
            c->tail = *b;
            *b = (*b)->next;
            r--;
        }
    }

    while (q > 0) {
    	M++;
        c->tail->next = *a;
        c->tail = *a;
        *a = (*a)->next;
        q--;
    }
    while (r > 0) {
    	M++;
        c->tail->next = *b;
        c->tail = *b;
        *b = (*b)->next;
        r--;
    }
}

void MergeSort(Stack *&S_head, Stack *&S_tail) {
	Stack *a = NULL;
    Stack *b = NULL;
	
	int n = Split(S_head, &a, &b);
	int p = 1;
	int q, r;
	Queue c[2];
	while (p < n) {
		c[0].tail = (Stack *)&(c[0].head);
		c[1].tail = (Stack *)&(c[1].head);
		int i = 0;
		int m = n;
		while (m > 0) {
			if (m >= p) {
				q = p;
			}
			else {
				q = m;
			}
			m -= q;
			if (m >= p) {
				r = p;
			}
			else {
				r = m;
			}
			m -= r;
			Merger(&a, q, &b, r, &c[i]);
			i = 1 - i;
		}
		a = c[0].head;
		b = c[1].head;
		p *= 2;
	}
	c[0].tail->next = NULL;
	S_head = c[0].head;
	S_tail = c[0].tail;
}

int main() {
	setlocale(LC_ALL, "Russian");
	Stack *S_head = NULL;
	Stack *S_tail = NULL;
	int n = 31;
	
	StackFillInc(n, S_head);
	printf("S: ");
	printStack(S_head);
	printf("\nСтэк S: Количество элементов = %d, Сумма = %d, Серии = %d\n\n", n, CheckSumStack(S_head), RunNumberStack(S_head));
    
    
    Stack *a_head = NULL;
    Stack *a_tail = NULL;
	Stack *b_head = NULL;
    Stack *b_tail = NULL;
    
    Split(S_head, &a_head, &b_head);
    
    int q = countElementsStack(a_head);
    int CheckSum_a = CheckSumStack(a_head);
    int RunNumber_a = RunNumberStack(a_head);
    printf("a: ");
	printStack(a_head);
    printf("\nСтэк a: Количество элементов = %d, Сумма = %d, Серии = %d\n\n", q, CheckSum_a, RunNumber_a);

	int r = countElementsStack(b_head);
    int CheckSum_b = CheckSumStack(b_head);
    int RunNumber_b = RunNumberStack(b_head);
	printf("b: ");
	printStack(b_head);
	printf("\nСтэк b: Количество элементов = %d, Сумма = %d, Серии = %d\n\n", r, CheckSum_b, RunNumber_b);
	
	Queue *c = (Queue *)malloc(sizeof(Queue));  
	if (c == NULL) {
        printf("Error!\n");
    }
	c->head = NULL;
	c->tail = NULL;
	
	Merger(&a_head, q, &b_head, r, c); 
	
	int count_c = countElementsQueue(c);
    int CheckSum_c = CheckSumQueue(c);
    int RunNumber_c = RunNumberQueue(c);
    printf("c: ");
    printQueue(c);
	printf("\nОчередь c: Количество элементов = %d, Сумма = %d, Серии = %d\n\n", count_c, CheckSum_c, RunNumber_c);
	
	S_head = NULL;
	S_tail = NULL;
	StackFillRand(n, S_head);
	printf("S (изначальное): ");
	printStack(S_head);
	MergeSort(S_head, S_tail);
	printf("\nS (сорт): ");
	printStack(S_head);
	printf("\nСумма = %d  Серии = %d\n", CheckSumStack(S_head), RunNumberStack(S_head));
	
	while (S_head != NULL) {
        cleanStack(&S_head);
    }
    while (a_head != NULL) {
        cleanStack(&a_head);
    }
    while (b_head != NULL) {
        cleanStack(&b_head);
    }
    while (c->head != NULL) {
        cleanQueue(&c);
    }
    free(c);
	
	
	printf("\n\n  Трудоемкость сортировки прямого слияния\n");
 	printf("\t    М+С(теор.)\t     (Мфакт+Сфакт)\t\n");
  	printf("N\t              \tУбыв.  \tСлуч.  \tВозр.\n");
    
  	for (int i = 100; i <= 500; i += 100) {
		int n = i;
        S_head = NULL;
        S_tail = NULL;
        int T = n * log2(n) + n * log2(n);
        M = 0;
        C = 0;
		    
        StackFillDec(n, S_head);
        MergeSort(S_head, S_tail);
        int T1 = M + C;
        M = 0;
        C = 0;

        while (S_head != NULL) {
            cleanStack(&S_head);
        }        
				
        StackFillRand(n, S_head);
        MergeSort(S_head, S_tail);
        int T2 = M + C;
        M = 0;
        C = 0;

        while (S_head != NULL) {
            cleanStack(&S_head);
        }
		
        StackFillInc(n, S_head);
        MergeSort(S_head, S_tail);
        int T3 = M + C;
        M = 0;
        C = 0;
		
		while (S_head != NULL) {
            cleanStack(&S_head);
        }
        
        printf("%d\t   %d     \t%d  \t%d  \t%d\n", n, T, T1, T2, T3);
    }
	
	return 0;
}

