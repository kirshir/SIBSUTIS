#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next; //указатель на следующий узел в списке
};

void insertAtEnd(struct Node** head, int data){ //функция добавления нового узла в конец списка 
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  //выделения памяти для нового узла 
	if (newNode == NULL){
		printf("Memory Error\n");
		exit(1);
	}
	newNode->data = data; //присваивание значения data полю data в новом узле
	newNode->next = NULL; //присваивание значения NULL указателю next в новом узле, так как он будет добавлен в конец списка.
	if (*head == NULL) { //строка проверяет, является ли голова списка NULL
		*head = newNode; //если список пуст, новый узел становится головой списка
		return;
	}
	
	struct Node* current = *head; //объявление указателя current, который используется для перемещения по списку. 
	//Изначально он устанавливается равным голове списка.
	
	while(current->next != NULL){ //итерирует через список до тех пор, пока не будет найден последний узел
		current = current->next; // (у которого next равен NULL)
	}
	current->next = newNode; //присваивает указателю next последнего узла ссылку на новый узел,
	// таким образом добавляя его в конец списка.
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


