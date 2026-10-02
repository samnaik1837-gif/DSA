#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

// Join
void join(string name) {
    Node* n = new Node{name, head};

    if (head == NULL) {
        head = n;
        n->next = head;
    }
    else {
        Node* p = head;
        while (p->next != head)
            p = p->next;

        p->next = n;
        n->next = head;
    }
}

// Leave
void leave(string name) {
    if (head == NULL) return;

    Node *p = head, *prev = NULL;

    do {
        if (p->name == name) {
            if (p == head) {
                if (p->next == head)
                    head = NULL;
                else {
                    Node* last = head;
                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                }
            }
            else
                prev->next = p->next;

            delete p;
            return;
        }

        prev = p;
        p = p->next;

    } while (p != head);
}

// Display
void display() {
    if (head == NULL) return;

    Node* p = head;

    do {
        cout << p->name << " ";
        p = p->next;
    } while (p != head);

    cout << endl;
}

int main() {
    join("A");
    join("B");
    join("C");

    display();

    leave("B");
    display();

    join("D");
    display();

    leave("A");
    display();

    return 0;
}