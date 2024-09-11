#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int M = 0;

struct tLE16 {
	tLE16 *next;
	union {
		short int data;
		unsigned char Digit[sizeof(data)];
	};
};

struct tLE32 {
	tLE32 *next;
	union {
		int data;
		unsigned char Digit[sizeof(data)];
	};
};

struct Queue16 {
	tLE16 *head;
	tLE16 *tail;
};

struct Queue32 {
	tLE32 *head;
	tLE32 *tail;
};

int CheckSumtLE16(tLE16 *head) {
    if (head == NULL)
        return 0;

    int sum = 0;
    tLE16 *p = head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int CheckSumtLE32(tLE32 *head) {
    if (head == NULL)
        return 0;

    int sum = 0;
    tLE32 *p = head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int RunNumbertLE16(tLE16 *head) {
    if (head == NULL)
        return 0;

	int ser = 1;
    tLE16 *p = head;
    tLE16 *nextNode = head->next;
    while (nextNode != NULL) {
        if(p->data > nextNode->data) {
            ser++;
        }
        p = nextNode;
        nextNode = nextNode->next;
    }
	return ser;
}

int RunNumbertLE32(tLE32 *head) {
    if (head == NULL)
        return 0;

	int ser = 1;
    tLE32 *p = head;
    tLE32 *nextNode = head->next;
    while (nextNode != NULL) {
        if(p->data > nextNode->data) {
            ser++;
        }
        p = nextNode;
        nextNode = nextNode->next;
    }
	return ser;
}

void Queue16FillInc(int n, tLE16 *(&head), tLE16 *(&tail))
{
    int i = 1;
    tLE16 *p;
    head = tail = new tLE16;
    head->next = tail->next = 0;
    tail->data = i;
    i++;
    do
    {
        p = new tLE16;
        p->data = i;
        tail->next = p;
        tail = p;
        i++;

    } while (i <= n);
    tail->next = 0;
}

void Queue16FillDec(int n, tLE16 *(&head), tLE16 *(&tail))
{
    int i = n;
    tLE16 *p;
    head = tail = new tLE16;
    head->next = tail->next = 0;
    tail->data = i;
    i--;
    do
    {
        p = new tLE16;
        p->data = i;
        tail->next = p;
        tail = p;
        i--;

    } while (i > 0);
    tail->next = 0;
}

void Queue16FillRand(int n, tLE16 *(&head), tLE16 *(&tail))
{
    srand(time(NULL));
    int i = 1;
    tLE16 *p;
    head = tail = new tLE16;
    head->next = tail->next = 0;
    tail->data = rand() % (n * 2);
    i++;
    do
    {
        p = new tLE16;
        p->data = rand() % (n * 2);
        tail->next = p;
        tail = p;
        i++;

    } while (i <= n);
    tail->next = 0;
}

void Queue32FillInc(int n, tLE32 *(&head), tLE32 *(&tail))
{
    int i = 1;
    tLE32 *p;
    head = tail = new tLE32;
    head->next = tail->next = 0;
    tail->data = i;
    i++;
    do
    {
        p = new tLE32;
        p->data = i;
        tail->next = p;
        tail = p;
        i++;

    } while (i <= n);
    tail->next = 0;
}

void Queue32FillDec(int n, tLE32 *(&head), tLE32 *(&tail))
{
    int i = n;
    tLE32 *p;
    head = tail = new tLE32;
    head->next = tail->next = 0;
    tail->data = i;
    i--;
    do
    {
        p = new tLE32;
        p->data = i;
        tail->next = p;
        tail = p;
        i--;

    } while (i > 0);
    tail->next = 0;
}

void Queue32FillRand(int n, tLE32 *(&head), tLE32 *(&tail))
{
    srand(time(NULL));
    int i = 1;
    tLE32 *p;
    head = tail = new tLE32;
    head->next = tail->next = 0;
    tail->data = rand() % ((n * 2) * 10000);
    i++;
    do
    {
        p = new tLE32;
        p->data = rand() % ((n * 2) * 10000);
        tail->next = p;
        tail = p;
        i++;

    } while (i <= n);
    tail->next = 0;
}

int cleanStack16(tLE16 **head) {
    if (*head == NULL) {
        printf("Stack is empty.");
        return -1;
    }
    int Data = (*head)->data;
    tLE16 *p = *head;
    *head = (*head)->next;
    free(p);
    return Data;
}

int cleanStack32(tLE32 **head) {
    if (*head == NULL) {
        printf("Stack is empty.");
        return -1;
    }
    int Data = (*head)->data;
    tLE32 *p = *head;
    *head = (*head)->next;
    free(p);
    return Data;
}

void printtLE16(tLE16 *head) {
    tLE16 *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void printtLE32(tLE32 *head) {
    tLE32 *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void DigitalSort16(tLE16 *(&S), tLE16 *(&tail)) {
	int KDI[2] = {1, 0};
	int L = 2;
	tLE16 *p;
	Queue16 q[256];
	unsigned char d;
	int k;
	
	for (int j = L - 1; j >= 0; j--) {
		for (int i = 0; i < 256; i++) {
			q[i].tail = (tLE16 *)&(q[i].head);
		}
		p = S;
		k = KDI[j];
		while (p != NULL) {
			M++;
			d = p->Digit[k];
			q[d].tail->next = p;
			q[d].tail = p;
			p = p->next;
		}
		p = (tLE16 *)&S;
		for (int i = 0; i < 256; i++) {
			if (q[i].tail != (tLE16 *)&q[i].head) {
				M++;
				p->next = q[i].head;
				p = q[i].tail;
			}
		}
		p->next = NULL;
	}
}

void DigitalSort32(tLE32 *(&S), tLE32 *(&tail)) {
	int KDI[4] = {3, 2, 1, 0};
	int L = 4;
	tLE32 *p;
	Queue32 q[256];
	unsigned char d;
	int k;
	
	for (int j = L - 1; j >= 0; j--) {
		for (int i = 0; i < 256; i++) {
			q[i].tail = (tLE32 *)&(q[i].head);
		}
		p = S;
		k = KDI[j];
		while (p != NULL) {
			M++;
			d = p->Digit[k];
			q[d].tail->next = p;
			q[d].tail = p;
			p = p->next;
		}
		p = (tLE32 *)&S;
		for (int i = 0; i < 256; i++) {
			if (q[i].tail != (tLE32 *)&q[i].head) {
				M++;
				p->next = q[i].head;
				p = q[i].tail;
			}
		}
		p->next = NULL;
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	tLE16 *S_head16 = NULL, *S_tail16 = NULL;
    tLE32 *S_head32 = NULL, *S_tail32 = NULL;
    
    int n = 100; 

 
    Queue16FillRand(n, S_head16, S_tail16);
    int ser16 = RunNumbertLE16(S_head16);
    int sum16 = CheckSumtLE16(S_head16);
    Queue32FillRand(n, S_head32, S_tail32);
    int ser32 = RunNumbertLE32(S_head32);
    int sum32 = CheckSumtLE32(S_head32);

    printf("Структура tLE16:\n");
    printtLE16(S_head16);
    printf("\nser = %d\nsum = %d\n\n", ser16, sum16);
    
    DigitalSort16(S_head16, S_tail16);
	ser16 = RunNumbertLE16(S_head16);
	sum16 = CheckSumtLE16(S_head16);
	printf("Структура tLE16 отсортированая:\n");
    printtLE16(S_head16);
    printf("\nser = %d\nsum = %d\n\n", ser16, sum16);

    printf("Структура tLE32:\n");
    printtLE32(S_head32);
    printf("\nser = %d\nsum = %d\n\n", ser32, sum32);

    DigitalSort32(S_head32, S_tail32);
	ser32 = RunNumbertLE32(S_head32);
	sum32 = CheckSumtLE32(S_head32);
	printf("Структура tLE32 отсортированая:\n");
    printtLE32(S_head32);
    printf("\nser = %d\nsum = %d\n\n", ser32, sum32);
    
    while (S_head16 != NULL) {
    	cleanStack16(&S_head16);	
	}
	while (S_head32 != NULL) {
    	cleanStack32(&S_head32);	
	}
    
    printf("    Трудоемкость цифровой сортировки DigitalSort\n");
    printf("N\tM\t\t     Mфакт\n");
    printf("       Теор.\t\tУбыв.\tСлуч.\tВозр.\n");
    for (int n = 100; n <= 500; n += 100) {
    	S_head32 = NULL;
    	S_tail32 = NULL;
    	M = 0;
    	int M_teor = n;
    	
		Queue32FillDec(n, S_head32, S_tail32);
		DigitalSort32(S_head32, S_tail32);
    	int M_dec = M;
    	while (S_head32 != NULL) {
    		cleanStack32(&S_head32);	
		}
    	M = 0;
    	
		Queue32FillRand(n, S_head32, S_tail32);
		DigitalSort32(S_head32, S_tail32);
    	int M_rand = M;
    	while (S_head32 != NULL) {
    		cleanStack32(&S_head32);	
		}
    	M = 0;
    	
    	Queue32FillInc(n, S_head32, S_tail32);
    	DigitalSort32(S_head32, S_tail32);
    	int M_inc = M;
    	while (S_head32 != NULL) {
    		cleanStack32(&S_head32);	
		}
    	M = 0;
    	
    	printf("%d    %d\t\t%d\t%d\t%d\n", n, M_teor, M_dec, M_rand, M_inc);
	}
	return 0;
}
