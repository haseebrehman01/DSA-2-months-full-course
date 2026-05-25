// ------------------------------------------------------------
// Question:
// Implement Two Stacks in One Array using Class in C++
//
// Requirements:
// 1. Create two stacks using a single array
// 2. Stack1 should grow from left to right
// 3. Stack2 should grow from right to left
// 4. Implement:
//      - push1()
//      - push2()
//      - pop1()
//      - pop2()
// 5. Handle Overflow and Underflow conditions
// ------------------------------------------------------------

#include <iostream>
using namespace std;

class TwoStack {

    // Pointer to dynamically created array
    int* arr;

    // Top index of Stack 1
    int top1;

    // Top index of Stack 2
    int top2;

    // Total size of array
    int capacity;

public:

    // ------------------------------------------------------------
    // Constructor
    // Runs automatically when object is created
    // ------------------------------------------------------------
    TwoStack(int size) {

        // Dynamically allocate array in heap memory
        arr = new int[size];

        // Stack1 starts from left side
        // Initially empty
        top1 = -1;

        // Stack2 starts from right side
        // Initially empty
        top2 = size;

        // Store total array size
        capacity = size;
    }

    // ------------------------------------------------------------
    // Destructor
    // Runs automatically when object is destroyed
    // Used to free heap memory
    // ------------------------------------------------------------
    ~TwoStack() {
        delete[] arr;
    }

    // ------------------------------------------------------------
    // Push element into Stack 1
    // ------------------------------------------------------------
    void push1(int elem) {

        // Overflow Condition
        // If both stacks become adjacent
        if ((top1 + 1) == top2) {

            cout << "Stack Overflow" << endl;
            return;
        }

        // Move top forward
        top1++;

        // Insert element
        arr[top1] = elem;
    }

    // ------------------------------------------------------------
    // Push element into Stack 2
    // ------------------------------------------------------------
    void push2(int elem) {

        // Overflow Condition
        if ((top1 + 1) == top2) {

            cout << "Stack Overflow" << endl;
            return;
        }

        // Move top backward
        top2--;

        // Insert element
        arr[top2] = elem;
    }

    // ------------------------------------------------------------
    // Pop element from Stack 1
    // ------------------------------------------------------------
    int pop1() {

        // Underflow Condition
        // Stack1 empty
        if (top1 == -1) {

            cout << "Stack Underflow" << endl;
            return -1;
        }

        // Store top element
        int ans = arr[top1];

        // Move top backward
        top1--;

        // Return deleted element
        return ans;
    }

    // ------------------------------------------------------------
    // Pop element from Stack 2
    // ------------------------------------------------------------
    int pop2() {

        // Underflow Condition
        // Stack2 empty
        if (top2 == capacity) {

            cout << "Stack Underflow" << endl;
            return -1;
        }

        // Store top element
        int ans = arr[top2];

        // Move top forward
        top2++;

        // Return deleted element
        return ans;
    }
};

int main() {

    // Create object of class
    // Array size = 10
    TwoStack s(10);

    // Insert elements in Stack1
    s.push1(10);
    s.push1(20);

    // Insert elements in Stack2
    s.push2(100);
    s.push2(200);

    // Remove from Stack1
    cout << "Pop from Stack1: " << s.pop1() << endl;

    // Remove from Stack2
    cout << "Pop from Stack2: " << s.pop2() << endl;

    return 0;
}