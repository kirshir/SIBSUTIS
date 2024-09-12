#include <iostream>
#include <cstdlib>

typedef struct node {
	std::string name;
	std::string gender;
	std::string hobby;
	struct node *next;
} list;

list * create(std::string i_name, std::string i_gender, std::string i_hobby) {
	list *new_node = (list *)malloc(sizeof(list));
	
	if (new_node != NULL) {
		new_node->name = i_name;
		new_node->gender = i_gender;
		new_node->hobby = i_hobby;
		new_node->next = NULL;
	}
	
	return new_node;
}

list *add(list *head, std::string i_name, std::string i_gender, std::string i_hobby) {

	if (head == NULL) {
		head = create(i_name, i_gender, i_hobby);
	} else {
		list *cursor = head;
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		list *new_node = create(i_name, i_gender, i_hobby);
		cursor->next = new_node;
	}
	
	return head;
}

void print_list(list *head) {
	while (head) {
		std::cout << head->name << " "<< head->gender << " " << head->hobby << "\n";
		head = head->next;
	}
}

void search(list *head, std::string name) {
	while (head) {
		if (head->name == name) {
			std::cout << head->name << " " << head->gender << " " << head->hobby << "\n";
		}
		head = head->next;
	}
}
list *del_item(list *head, std::string name) {
	if (head->name == name) {
		list *temp = head;
		head = head->next;
		free(temp);
	} else {
		list *cursor = head;
		while (cursor->next->name != name) {
			cursor = cursor->next;
		}
		list *del = cursor->next;
		cursor->next = del->next;
		free(del);
	}
	
	return head;
}
int main()
{
	list *a = NULL;
	a = add(a, "Dasha", "Woman", "Smoker");
	//a = add(a, "Abdulaziz", "Man", "Nike");
	a = add(a, "Danil", "Woman", "Hobbyhorsing");
	a = add(a, "Abdulaziz", "?", "Adidas");

	a = del_item(a, "Vana");

	print_list(a);
	return 0;
}
