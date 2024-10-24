#include <iostream>

class List {
protected:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}     //список инициализации    
    };
    Node* head;
    int size;
    static int total_elements;   //Статический элемент класса для общего кол-ва элементов во всех списках

public:
    List(): head(nullptr), size(0) {};

    List(int value): head(new Node(value)), size(1) {
        total_elements++;
    }

    //Добавление в конец списка
    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
        total_elements++;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    static int getTotalElements() {
        return total_elements;
    }

    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int List::total_elements = 0;


class Stack : public List {
public:
    Stack(): List() {};
    Stack(int value): List(value) {};

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
        total_elements++;
    }

    //Удаление и возврат с вершины стека с исключением
    int pop() {
        if (head == nullptr) {
            throw std::runtime_error("Error: Stack is empty!");
        }

        int topValue = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--, total_elements--;
        return topValue;
    }

    void print() {
        std::cout << "Stack: ";
        List::print();
    }
};

class Queue: public List{
private:
    Node* tail;

public:
    Queue(): List(), tail(nullptr) {};
    Queue(int value): List(value), tail(head) {};

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        total_elements++;
    }

    //Удаление и возрат с начала очереди с исключением
    int dequeue() {
        if (head == nullptr) {
            throw std::runtime_error("Error: Queue is empty!");
        }
        int frontValue = head->data;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        size--, total_elements--;
        return frontValue;
    }

    void print() {
        std::cout << "Queue: ";
        List::print();
    }
};

int main() {
    try {
        Stack stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.print();
        std::cout << "Pop from stack: " << stack.pop() << std::endl;
        stack.print();

        Queue queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.print();
        std::cout << "Dequeue from queue: " << queue.dequeue() << std::endl;
        queue.print();
        std::cout << "Dequeue from queue: " << queue.dequeue() << std::endl;
        queue.print();

        Queue emptyQ;
        std::cout << "Trying to dequeue from empty queue:" << std::endl;
        emptyQ.dequeue();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Total elements in lists: " << List::getTotalElements() << std::endl;
    return 0;
}