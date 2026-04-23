#include <iostream>
using namespace std;

int main() {

    // ================= BASIC POINTER =================
    // int a = 10;
    // int *ptr = &a;  

    // cout << "Value of a: " << a << endl;          // 10
    // cout << "Value of *ptr: " << *ptr << endl;    // 10 (dereference)
    // cout << "Address of ptr: " << &ptr << endl;   // address of pointer variable
    // cout << "Address of a (stored in ptr): " << ptr << endl; // address of a

    // a++;  // increment value of a

    // cout << "Updated value of a: " << a << endl;       // 11
    // cout << "Updated value via pointer: " << *ptr << endl; // 11

    // cout << "Actual address of a: " << &a << endl; // same as ptr

    cout << "\n================ POINTER TO POINTER ================\n";

    // ================= POINTER TO POINTER =================
    // int **ptr2 = &ptr;

    // cout << "Address of ptr: " << &ptr << endl;     // address of ptr
    // cout << "Value of ptr (address of a): " << *ptr2 << endl; // same as ptr
    // cout << "Value of a using **ptr2: " << **ptr2 << endl;    // 11

    cout << "\n================ DEREFERENCE OPERATIONS ================\n";

    // ================= DEREFERENCE OPERATIONS =================
    // int b = 20;
    // int* p = &b;
    // int** p2 = &p;

    // cout << "*(&b): " << *(&b) << endl;   // 20 (value of b)
    // cout << "*(&p): " << *(&p) << endl;   // address of b
    // cout << "p: " << p << endl;           // address of b
    // cout << "*p: " << *p << endl;         // 20
    // cout << "p2: " << p2 << endl;         // address of p
    // cout << "**p2: " << **p2 << endl;     // 20

    // cout << "*(p2): " << *(p2) << endl;   // address of b

    cout << "\n================ NULL POINTER ================\n";

    // // ================= NULL POINTER =================
    // int* point = nullptr;  // safe initialization

    // if (point == nullptr) {
    //     cout << "Pointer is null, cannot dereference!" << endl;
    // }

    cout << "\n================ PRACTICE QUESTION ================\n";

    // ================= PRACTICE QUESTION =================
    // int x = 5;
    // int *p1 = &x;
    // int **q = &p1;

    // cout << "*p1: " << *p1 << endl;   // 5
    // cout << "**q: " << **q << endl;   // 5
    // cout << "p1 (address of x): " << p1 << endl;
    // cout << "*q (address of x): " << *q << endl;

//     int a = 10, b = 20;
// int *p = &a;

// p = &b;
// cout << a << endl;//1 = 10 



// ================= Array pointers =================

// NOTE:
// In C++, an array is NOT exactly a pointer,
// but in most expressions it "decays" into a pointer to its first element (arr[0]).

// Example:
int arr[] = {1, 2, 3, 4, 5};

// arr behaves like a constant pointer to the first element
// BUT IMPORTANT:
// - You cannot change where arr points
// - Because array name is NOT a normal pointer variable

// ❌ This will cause COMPILATION ERROR
// arr = &a;  
// Reason: 'arr' is not a modifiable lvalue (array name is fixed in memory)

// ===================================================

int a = 10;

// ✅ Valid: changing value inside array, not the pointer itself
arr[0] = a;  
// Now arr[0] becomes 10 (first element updated)

cout << "arr[0] = " << arr[0] << endl;  // Output: 10
cout << "arr[1] = " << arr[1] << endl;  // Output: 2

// ===================================================
// KEY UNDERSTANDING:

// int arr[] = {1,2,4,56,0};

// Think of it like:
// arr → holds address of arr[0]
// BUT:
// arr is NOT a real pointer variable you can reassign

// So conceptually:
// arr == &arr[0]   (same address)
// but:
// arr = something else ❌ not allowed

// ===================================================
// SIMPLE SUMMARY:

// ✔ arr behaves like pointer to first element
// ❌ but arr itself is constant (cannot change address)
// ✔ arr[i] means *(arr + i)

    return 0;
}