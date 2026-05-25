#include <iostream>
using namespace std;

class Stack {

    // Pointer to dynamically allocated array
    // Stores address of heap memory array
    int *arr;

    // Index of current top element
    // top = -1 means stack is empty
    int top;

    // Maximum capacity of stack
    int capacity;

public:

    // ---------------------------------------------------
    // Constructor
    // Automatically called when object is created
    // Initializes stack memory and variables
    // ---------------------------------------------------

    Stack(int size) {

        // Set stack maximum capacity
        capacity = size;

        // Create dynamic array in heap memory
        arr = new int[capacity];

        // Initially stack is empty
        top = -1;
    }

    // ---------------------------------------------------
    // push() -> insert element at top
    // ---------------------------------------------------
    // Time Complexity: O(1)
    // ---------------------------------------------------

    void push(int value) {

        // Check overflow condition
        if(top == capacity - 1) {

            cout << "Stack Overflow" << endl;
            return;
        }

        // Move top pointer forward
        top++;

        // Insert element at top index
        arr[top] = value;

        cout << value << " pushed into stack" << endl;
    }

    // ---------------------------------------------------
    // pop() -> remove top element
    // ---------------------------------------------------
    // Time Complexity: O(1)
    // ---------------------------------------------------

    void pop() {

        // Check underflow condition
        if(top == -1) {

            cout << "Stack Underflow" << endl;
            return;
        }

        // Print element being removed
        cout << arr[top] << " removed from stack" << endl;

        // Logical deletion:
        // We are NOT deleting memory,
        // just moving top backward
        top--;
    }

    // ---------------------------------------------------
    // peek() -> returns top element without removing it
    // Similar to STL stack top()
    // ---------------------------------------------------

    int peek() {

        // Check if stack is empty
        if(top == -1) {

            cout << "Stack is empty" << endl;
            return -1;
        }

        // Return top element
        return arr[top];
    }

    // ---------------------------------------------------
    // isEmpty() -> checks if stack is empty
    // ---------------------------------------------------

    bool isEmpty() {

        return top == -1;
    }

    // ---------------------------------------------------
    // isFull() -> checks if stack is full
    // ---------------------------------------------------

    bool isFull() {

        return top == capacity - 1;
    }

    // ---------------------------------------------------
    // size() -> returns number of elements in stack
    // ---------------------------------------------------

    int size() {

        return top + 1;
    }

    // ---------------------------------------------------
    // display() -> prints stack elements (top to bottom)
    // Stack follows LIFO order
    // ---------------------------------------------------

    void display() {

        if(top == -1) {

            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";

        for(int i = top; i >= 0; i--) {

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    // Create stack with capacity 5
    Stack s(5);

    /*
        Stack visualization (LIFO):

            TOP
             |
             v

            50
            40
            30
            20
            10
    */

    // Push elements into stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << endl;

    // Display stack elements
    s.display();

    // peek() returns top element without removing it
    cout << "Top element: " << s.peek() << endl;

    // size() returns total number of elements
    cout << "Stack size: " << s.size() << endl;

    cout << endl;

    // Pop two elements from stack
    s.pop();
    s.pop();

    cout << endl;

    // Display updated stack
    s.display();

    // Check if stack is empty
    cout << "Is stack empty? ";

    if(s.isEmpty()) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl;

    // Check if stack is full
    cout << "Is stack full? ";

    if(s.isFull()) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl << endl;

    /*
        ==============================
        STACK THEORY (IMPORTANT)
        ==============================

        1. Stack is a linear data structure

        2. It follows LIFO:
           Last In First Out

        3. Implementation uses:
           - dynamic array (arr)
           - top index

        4. top = -1 means stack is empty

        5. push():
           - inserts element at top
           - increments top

        6. pop():
           - removes element logically
           - decrements top
           (memory is NOT physically deleted)

        7. peek():
           - returns top element
           - does NOT remove it

        8. Stack Overflow:
           when top == capacity - 1

        9. Stack Underflow:
           when pop/peek on empty stack

        10. Time Complexity:
            push  -> O(1)
            pop   -> O(1)
            peek  -> O(1)

        11. arr is a pointer:
            stores address of heap array

        12. Key idea:
            pop() only moves top pointer,
            element still exists in memory but is ignored
    */

    return 0;
}