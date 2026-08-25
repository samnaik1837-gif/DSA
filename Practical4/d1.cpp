#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        display();
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        display();
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;

            display();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        display();
    }

    void display() {
        Node* temp = head;

        cout << "Queue: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    LinkedList queue;

    queue.insertFront(10);

    queue.insertEnd(20);
    queue.insertEnd(30);

    queue.insertFront(5);
    queue.insertAtPosition(15, 3);

    queue.insertAtPosition(50, 10);

    return 0;
}