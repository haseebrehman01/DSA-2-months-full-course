#include <iostream>
using namespace std;

// ---------------------------------------------------
// Node class for Linked List
// Each node stores:
// 1. data
// 2. pointer to next node
// ---------------------------------------------------

class Node {

public:

    int data;
    Node* next;

    // Constructor
    Node(int d) {

        data = d;
        next = NULL;
    }
};

// ---------------------------------------------------
// Stack implementation using Linked List
// ---------------------------------------------------

class Stack {

    // Pointer to top node
    Node* top;

public:

    // ---------------------------------------------------
    // Constructor
    // ---------------------------------------------------

    Stack() {

        // Initially stack is empty
        top = NULL;
    }

    // ---------------------------------------------------
    // push()
    // Inserts element at top
    // Time Complexity = O(1)
    // ---------------------------------------------------

    void push(int value) {

        // Create new node
        Node* newNode = new Node(value);

        // New node points to current top
        newNode->next = top;

        // Move top to new node
        top = newNode;
    }

    // ---------------------------------------------------
    // pop()
    // Removes top element
    // Time Complexity = O(1)
    // ---------------------------------------------------

    void pop() {

        // Underflow condition
        if(top == NULL) {

            cout << "Stack Underflow" << endl;
            return;
        }

        // Temporary pointer
        Node* temp = top;

        // Move top forward
        top = top->next;

        // Delete old top node
        delete temp;
    }

    // ---------------------------------------------------
    // peek() / top()
    // Returns top element
    // Time Complexity = O(1)
    // ---------------------------------------------------

    int peek() {

        if(top == NULL) {

            cout << "Stack is Empty" << endl;
            return -1;
        }

        return top->data;
    }

    // ---------------------------------------------------
    // empty()
    // Checks whether stack is empty
    // ---------------------------------------------------

    bool empty() {

        return top == NULL;
    }

    // ---------------------------------------------------
    // display()
    // Stack traversal
    // ---------------------------------------------------

    void display() {

        if(top == NULL) {

            cout << "Stack is Empty" << endl;
            return;
        }

        Node* temp = top;

        cout << "Stack Elements: ";

        while(temp != NULL) {

            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }

    // ---------------------------------------------------
    // Destructor
    // Automatically frees memory
    // ---------------------------------------------------

    ~Stack() {

        while(top != NULL) {

            Node* temp = top;

            top = top->next;

            delete temp;
        }
    }
};

int main() {

    // Create stack object
    Stack s;

    // ---------------------------------------------------
    // push()
    // ---------------------------------------------------

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    /*
                TOP
                 |
                 v

                50
                40
                30
                20
                10
    */

    // ---------------------------------------------------
    // peek()
    // ---------------------------------------------------

    cout << "Top Element: " << s.peek() << endl;

    // ---------------------------------------------------
    // display()
    // ---------------------------------------------------

    s.display();

    // ---------------------------------------------------
    // pop()
    // ---------------------------------------------------

    s.pop();

    cout << "After Pop:" << endl;

    s.display();

    // ---------------------------------------------------
    // empty()
    // ---------------------------------------------------

    if(s.empty()) {

        cout << "Stack is Empty" << endl;

    } else {

        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}