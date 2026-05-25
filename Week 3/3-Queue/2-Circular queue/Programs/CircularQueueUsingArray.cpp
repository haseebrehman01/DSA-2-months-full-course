#include <iostream>
using namespace std;

// Circular Queue class
class CircularQueue {

private:
    int* arr;   // dynamic array to store queue elements
    int front;  // points to the first element (deletion happens here)
    int rear;   // points to the last inserted element
    int size;   // maximum capacity of the queue

public:

    // Constructor: initializes the queue
    CircularQueue(int s) {

        size = s;                // set queue size

        arr = new int[size];     // dynamically allocate array

        front = -1;              // -1 means queue is initially empty
        rear = -1;               // -1 means no elements inserted yet
    }

    // =========================
    // CHECK IF QUEUE IS EMPTY
    // =========================
    bool isEmpty() {

        // If front is -1, it means no valid element exists
        return (front == -1);
    }

    // =========================
    // CHECK IF QUEUE IS FULL
    // =========================
    bool isFull() {

        // Circular condition:
        // If next position of rear meets front, queue is full

        return ((rear + 1) % size == front);
    }

    // =========================
    // ENQUEUE OPERATION (INSERT)
    // =========================
    void enqueue(int data) {

        // 1. Check overflow condition
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        // 2. If inserting the first element
        // initialize front to 0
        if (front == -1) {
            front = 0;
        }

        // 3. Move rear in circular manner
        rear = (rear + 1) % size;

        // 4. Insert data at rear position
        arr[rear] = data;
    }

    // =========================
    // DEQUEUE OPERATION (DELETE)
    // =========================
    void dequeue() {

        // 1. Check underflow condition
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        // 2. Single element case
        // If front and rear are equal, only one element exists
        if (front == rear) {

            // After deletion, queue becomes empty
            front = rear = -1;
        }

        // 3. Normal case (more than one element)
        else {

            // Move front forward in circular manner
            // This logically removes the front element
            front = (front + 1) % size;
        }
    }

    // =========================
    // GET FRONT ELEMENT
    // =========================
    int getFront() {

        // If queue is empty, no front exists
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        // Return front element without removing it
        return arr[front];
    }

    // =========================
    // DISPLAY QUEUE ELEMENTS
    // =========================
    void display() {

        // If queue is empty, nothing to show
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;

        // Traverse circularly from front to rear
        while (true) {

            cout << arr[i] << " ";

            // Stop when we reach rear
            if (i == rear) break;

            // Move index circularly
            i = (i + 1) % size;
        }

        cout << endl;
    }
};