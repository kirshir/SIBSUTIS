#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next; //��������� �� ��������� ���� � ������
};

void insertAtEnd(struct Node** head, int data){ //������� ���������� ������ ���� � ����� ������ 
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  //��������� ������ ��� ������ ���� 
	if (newNode == NULL){
		printf("Memory Error\n");
		exit(1);
	}
	newNode->data = data; //������������ �������� data ���� data � ����� ����
	newNode->next = NULL; //������������ �������� NULL ��������� next � ����� ����, ��� ��� �� ����� �������� � ����� ������.
	if (*head == NULL) { //������ ���������, �������� �� ������ ������ NULL
		*head = newNode; //���� ������ ����, ����� ���� ���������� ������� ������
		return;
	}
	
	struct Node* current = *head; //���������� ��������� current, ������� ������������ ��� ����������� �� ������. 
	//���������� �� ��������������� ������ ������ ������.
	
	while(current->next != NULL){ //��������� ����� ������ �� ��� ���, ���� �� ����� ������ ��������� ����
		current = current->next; // (� �������� next ����� NULL)
	}
	current->next = newNode; //����������� ��������� next ���������� ���� ������ �� ����� ����,
	// ����� ������� �������� ��� � ����� ������.
}

void printList(struct Node* head){
	struct Node* current = head;
	while (current != NULL){
		printf("%d ", current->data);
		current= current->next;
	}
	printf("\n");
}

int main() {
	struct Node* head = NULL;
	
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	printf("List:\n");
	printList(head);	
	struct Node *temp;
	while (head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	return 0;
}


