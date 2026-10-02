#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

Node *head = NULL;

void addFirst(string s) {
    Node *n = new Node{s, NULL, head};
    if (head) head->prev = n;
    head = n;
}

void addLast(string s) {
    Node *n = new Node{s, NULL, NULL};

    if (head == NULL) {
        head = n;
        return;
    }

    Node *p = head;
    while (p->next)
        p = p->next;

    p->next = n;
    n->prev = p;
}

void insertAfter(string oldSong, string newSong) {
    Node *p = head;

    while (p && p->song != oldSong)
        p = p->next;

    if (!p) {
        cout << "Song not found\n";
        return;
    }

    Node *n = new Node{newSong, p, p->next};

    if (p->next)
        p->next->prev = n;

    p->next = n;
}

void removeFirst() {
    if (!head) return;

    Node *temp = head;
    head = head->next;

    if (head)
        head->prev = NULL;

    delete temp;
}
void display() {
    Node *p = head;
    int count = 0;

    while (p) {
        cout << p->song << " ";
        count++;
        p = p->next;
    }
    cout << "\nCount = " << count << endl;
}

int main() {
    addFirst("A");
    addLast("B");
    addLast("C");

    display();

    insertAfter("B", "X");
    display();

    removeFirst();
    display();

    return 0;
}