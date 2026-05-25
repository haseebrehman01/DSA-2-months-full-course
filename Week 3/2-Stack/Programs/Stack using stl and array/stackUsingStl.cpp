#include <iostream>
#include <stack> // STL stack library  //stl library
using namespace std;

int main() {

    // Stack declaration
    // This stack stores integer values
    stack<int> s;
     s.pop();
     cout << s.top() << "haseeb" << endl;
    // ---------------------------------------------------
    // STACK THEORY
    // ---------------------------------------------------

    // Stack follows:
    // LIFO = Last In First Out
    // The last inserted element is removed first

    // STL stack is a container adaptor
    // By default, it internally uses deque

    // ---------------------------------------------------
    // push() -> inserts element at the top
    // Time Complexity = O(1)
    // ---------------------------------------------------

   //  s.push(10);
   //  s.push(20);
   //  s.push(30);
   //  s.push(40);
   //  s.push(50);

   //  /*
   //              TOP
   //               |
   //               v

   //              50
   //              40
   //              30
   //              20
   //              10
   //  */

   //  // ---------------------------------------------------
   //  // top() -> accesses the top element
   //  // Time Complexity = O(1)
   //  // ---------------------------------------------------

   //  cout << "Top element: " << s.top() << endl;//50

   //  // ---------------------------------------------------
   //  // size() -> returns total number of elements
   //  // Time Complexity = O(1)
   //  // ---------------------------------------------------

   //  cout << "Stack size: " << s.size() << endl;//5



   //  // ---------------------------------------------------
   //  // Stack traversal
   //  // Stack does not support direct traversal
   //  // So we use:
   //  // while loop + top() + pop()
   //  // ---------------------------------------------------

   //  cout << "Stack elements: ";

   //  while(!s.empty()) {  //s.empty -- > 0 --> !0 ---> 1

   //      // top() returns current top element
   //      cout << s.top() << " "; //50,40,30,20,10

   //      // pop() removes the top element
   //      // NOTE:
   //      // pop() does NOT return any value
   //      s.pop();
   //  }

   //  cout << endl ;

   //  // ---------------------------------------------------
   //  // IMPORTANT:
   //  // Never use top() or pop() on an empty stack
   //  // It may cause undefined behavior or crash
   //  // ---------------------------------------------------

   //  if(!s.empty()) {

   //      cout << "Top element: " << s.top() << endl;
   //      cout << "Stack is not empty";

   //  } else {

   //      cout << "Stack is empty";
   //  }

   //  cout << endl << endl;

   //  // ---------------------------------------------------
   //  // IMPORTANT THEORY POINTS
   //  // ---------------------------------------------------

   //  /*
   //      1. Stack is a linear data structure

   //      2. Stack follows LIFO
   //         (Last In First Out)

   //      3. STL stack internally uses deque by default

   //      4. Stack does NOT support:
   //         ❌ indexing
   //         ❌ random access
   //         ❌ direct traversal

   //      5. Main stack functions:
   //         push()
   //         pop()
   //         top()
   //         size()
   //         empty()

   //      6. Time Complexities:
   //         push()  -> O(1)
   //         pop()   -> O(1)
   //         top()   -> O(1)

   //      7. Real-world applications:
   //         - Function calls
   //         - Recursion
   //         - Browser history
   //         - Undo feature
   //         - DFS
   //         - Parentheses matching
   //         - Expression evaluation

   //      8. Stack reverses order because
   //         insertion and deletion both happen at the top
   //  */

    return 0;
}