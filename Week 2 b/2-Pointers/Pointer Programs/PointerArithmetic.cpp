#include <iostream>
using namespace std;

int main() {

    // ================= POINTER ARITHMETIC =================
    // Pointer arithmetic means:
    // When you increase or decrease a pointer,
    // it moves based on the size of the data type (not just 1 byte).

    // Example:
    // int usually takes 4 bytes in memory

    int a = 70;
    int *p = &a;

    cout << p << endl;        // prints address of a
    cout << sizeof(p) << endl; // size of pointer (usually 8 bytes in 64-bit system)

    // p++ means:
    // move pointer to next integer location
    // so it jumps by 4 bytes (size of int)

    // p--;
    // moves pointer back by 1 int (4 bytes)

    // NOTE:
    // This is useful mainly with arrays, not single variables


    // ================= ARRAY + POINTER =================

    int arr[] = {20, 80, 40, 90, 10};

    // arr automatically becomes a pointer to first element (arr[0])
    // so:
    // arr == &arr[0]

    int *ptr = arr; // pointer points to first element (20)

    // Memory idea (example):
    // 100 -> 20
    // 104 -> 80
    // 108 -> 40
    // 112 -> 90
    // 116 -> 10

    cout << *(ptr + 1) << endl; 
    // ptr + 1 moves to second element (80)

    cout << *(ptr + 3) << endl;
    // ptr + 3 moves to fourth element (90)

    // move pointer forward by 1 element
    ptr++;

    cout << *ptr << endl; 
    // now ptr points to 80 (second element)

    return 0;
}