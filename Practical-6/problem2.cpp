#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

// Visit a new page
void visit(string page) {
    Node* newNode = new Node();
    newNode->page = page;
    newNode->next = top;
    top = newNode;

    cout << "Current Page: " << top->page << endl;
}

// Press Back
void back() {
    if (top == NULL) {
        cout << "No page in history!" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    if (top != NULL)
        cout << "Current Page: " << top->page << endl;
    else
        cout << "No page left in history!" << endl;
}

int main() {
    visit("Google");
    visit("YouTube");
    visit("GitHub");

    back();
    back();
    back();
    back();

    return 0;
}