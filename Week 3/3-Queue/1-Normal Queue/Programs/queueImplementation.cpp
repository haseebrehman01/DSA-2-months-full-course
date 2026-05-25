#include <iostream>
using namespace std;



class Queue {

    // Pointer for dynamically allocated array
    // Queue elements will be stored in this array
    int* arr;

    // front points to the index of the first element
    // that will be removed next
    int front;

    // rear points to the next empty position
    // where a new element will be inserted
    int rear;

    // Maximum size/capacity of queue
    int size;

public:

    // ---------------------------------------------------
    // Constructor
    // Automatically runs when object is created
    // ---------------------------------------------------
    Queue(int s) {

        // Dynamically create array in heap memory
        arr = new int[s];

        // Initially queue is empty
        // Both front and rear start from 0
        front = 0;
        rear = 0;

        // Store queue capacity
        size = s;
    }



    // ---------------------------------------------------
    // Check whether queue is empty
    // ---------------------------------------------------
    bool isEmpty() {

        /*
            Logic:

            If front == rear
            it means there are no elements present.

            Example:

            front = 0
            rear  = 0

            Queue is empty.

            Why?

            Because rear always stays one step ahead
            after insertion.

            If both become equal again,
            it means all elements were removed.
        */

        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }



    // ---------------------------------------------------
    // Enqueue Operation
    // Insert element from rear side
    // ---------------------------------------------------
    void enqueue(int data) {

        /*
            Queue Full Condition

            rear == size

            Example:
            size = 5

            Valid indexes:
            0 1 2 3 4

            If rear becomes 5,
            there is no more space left.

            So insertion is impossible.
        */

        if(rear == size) {

            cout << "Queue is full" << endl;

            // return stops function immediately
            // otherwise invalid insertion may happen
            return;
        }


        /*
            Insert new element at rear position
        */
        arr[rear] = data;


        /*
            Move rear forward

            rear always points to next empty position.

            Example:

            Before insertion:
            rear = 0

            arr[0] = 10

            After insertion:
            rear = 1
        */
        rear++;
    }



    // ---------------------------------------------------
    // Dequeue Operation
    // Remove element from front side
    // ---------------------------------------------------
    int dequeue() {

        /*
            Empty Queue Condition

            If front == rear
            there are no elements available to remove.
        */
        if(front == rear) {

            cout << "Queue is empty" << endl;

            return -1;
        }


        /*
            Store current front element
            because after incrementing front,
            old element access will be lost.
        */
        int ans = arr[front];


        /*
            Move front forward

            Example:

            Queue:
            [10,20,30]

            front = 0

            After dequeue:
            front = 1

            Now logically queue becomes:
            [20,30]
        */
        front++;



        /*
            Reset Condition

            If after deletion:
            front == rear

            It means queue became completely empty.

            So reset both pointers back to 0.

            This allows queue reuse from beginning.

            Example:

            Before reset:
            front = 5
            rear  = 5

            After reset:
            front = 0
            rear  = 0
        */
        if(front == rear) {

            front = 0;
            rear = 0;
        }


        /*
            Return removed element
        */
        return ans;
    }



    // ---------------------------------------------------
    // Get Front Element
    // Returns first element of queue
    // ---------------------------------------------------
    int getFront() {

        /*
            If queue is empty,
            no front element exists.
        */
        if(front == rear) {

            cout << "Queue is empty" << endl;

            return -1;
        }


        /*
            Return current front element
            without removing it
        */
        return arr[front];
    }
};




int main() {

    // Create queue of size 5
    Queue q(5);


    // Insert elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);


    /*
        Queue visualization:

        Index:   0    1    2
        Value:  10   20   30

        front = 0
        rear  = 3
    */


    // Access front element
    cout << "Front Element: "
         << q.getFront() << endl;


    // Remove front element
    cout << "Dequeued Element: "
         << q.dequeue() << endl;


    /*
        After dequeue:

        Logical Queue:
        [20,30]

        front = 1
        rear  = 3
    */


    // New front element
    cout << "New Front Element: "
         << q.getFront() << endl;


    return 0;
}