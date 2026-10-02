#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int n) { 
        capacity = n;
        top = -1;
    }
    void push(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full. Cannot place tray " << tray << endl;
            return;
        }

        top++;
        arr[top] = tray;

        cout << "Placed tray: " << tray << endl;
        cout << "Current top: " << arr[top] << endl;
    }
    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty. Cannot take tray." << endl;
            return;
        }

        cout << "Taken tray: " << arr[top] << endl;
        top--;

        if (top == -1)
            cout << "Current top: None" << endl;
        else
            cout << "Current top: " << arr[top] << endl;
    }
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Stack s(n);

    int choice, value;

    while (true) {
        cout << "\n1. Place Tray (Push)";
        cout << "\n2. Take Tray (Pop)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}