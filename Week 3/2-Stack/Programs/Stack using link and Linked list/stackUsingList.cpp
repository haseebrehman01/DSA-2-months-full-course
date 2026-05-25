#include <iostream>
#include <list> // STL Doubly Linked List
using namespace std;

int main() {

    // ---------------------------------------------------
    // Stack implementation using STL List
    // ---------------------------------------------------

    // list<int> creates a doubly linked list
    list<int> stack;

    // ---------------------------------------------------
    // STACK THEORY
    // ---------------------------------------------------

    /*
        We can implement stack using list

        Stack follows:
        LIFO = Last In First Out

        In list:
        - push_back() acts like push()
        - pop_back() acts like pop()
        - back() acts like top()

        Why?

        Because stack insertion/deletion
        happens at one side only.

        List insertion/deletion at back = O(1)
    */

    // ---------------------------------------------------
    // push()
    // Using push_back()
    // Time Complexity = O(1)
    // ---------------------------------------------------

    stack.push_back(10);
    stack.push_back(20);
    stack.push_back(30);
    stack.push_back(40);
    stack.push_back(50);

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
    // top()
    // Using back()
    // Time Complexity = O(1)
    // ---------------------------------------------------

    cout << "Top Element: " << stack.back() << endl;

    // ---------------------------------------------------
    // size()
    // ---------------------------------------------------

    cout << "Stack Size: " << stack.size() << endl;

    // ---------------------------------------------------
    // Traversal
    // ---------------------------------------------------

    cout << "Stack Elements: ";

    // reverse traversal because
    // last inserted element is top
    for(auto it = stack.rbegin(); it != stack.rend(); it++) {

        cout << *it << " ";
    }

    cout << endl;

    // ---------------------------------------------------
    // pop()
    // Using pop_back()
    // Time Complexity = O(1)
    // ---------------------------------------------------

    stack.pop_back();

    cout << "After Pop: ";

    for(auto it = stack.rbegin(); it != stack.rend(); it++) {

        cout << *it << " ";
    }

    cout << endl;

    // ---------------------------------------------------
    // empty()
    // ---------------------------------------------------

    if(stack.empty()) {

        cout << "Stack is Empty" << endl;

    } else {

        cout << "Stack is Not Empty" << endl;
    }

    // ---------------------------------------------------
    // IMPORTANT THEORY POINTS
    // ---------------------------------------------------

    /*
        1. list is a doubly linked list

        2. Stack can be implemented using list

        3. Functions used:

           push_back() -> push
           pop_back()  -> pop
           back()      -> top

        4. Time Complexities:

           push_back() -> O(1)
           pop_back()  -> O(1)
           back()      -> O(1)

        5. Advantage over array:
           Dynamic size

        6. Disadvantage:
           Extra memory for pointers

        7. STL stack internally uses deque by default,
           NOT list
    */

    return 0;
}