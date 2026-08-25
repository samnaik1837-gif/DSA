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
    }
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
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
    }
    void deleteByValue(int value) {

        // If list is empty
        if (head == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << value << " deleted." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << value << " not found!" << endl;
            return;
        }
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;

        cout << value << " deleted." << endl;
    }

    void display() {
        Node* temp = head;

        cout << "Queue (Front to Back): ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node* temp) {

        if (temp == NULL) {
            return;
        }

        
        reversePrint(temp->next);

        
        cout << temp->data << " ";
    }

    
    void displayReverse() {
        cout << "Queue (Back to Front): ";
        reversePrint(head);
        cout << endl;
    }
};

int main() {

    LinkedList queue;

    
    queue.insertEnd(10);
    queue.insertEnd(20);
    queue.insertEnd(30);
    queue.insertEnd(40);
    queue.insertEnd(50);

    
    queue.display();

    
    queue.deleteByValue(30);

    
    queue.display();

    
    queue.displayReverse();

    
    queue.display();

    return 0;
}