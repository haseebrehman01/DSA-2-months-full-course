#include <iostream>
using namespace std;

int main() {

    // 2D array (3 rows, 3 columns)
    // Memory is stored in row-major order (continuous block)
    int a[3][3] = {
        {6, 2, 5},
        {0, 1, 3},
        {4, 9, 8}
    };

    // Accessing direct element using normal indexing
    cout << "a[0][0] = " << a[0][0] << endl;

    // ---------------- POINTER BASICS ----------------
    cout << "\n--- Pointer Basics ---" << endl;

    // a → address of first row (type: int (*)[3])
    // *a → first row (decays to pointer of first element of row)
    cout << "*a (first row concept) = " << *a << endl;

    // **a → value at first row, first column (actual element)
    cout << "**a (first element) = " << **a << endl;

    // ---------------- POINTER EXPRESSION ----------------
    cout << "\n--- Pointer Expressions ---" << endl;

    // *(*a + 1)
    // *a → row 0
    // (*a + 1) → second element in row 0
    // result = 2
    cout << "*(*a + 1) = " << *(*a + 1) << endl;

    // *(*(a + 1) + 2)
    // a + 1 → second row
    // *(a + 1) → row 1
    // +2 → third column
    // result = 3
    cout << "*(*(a + 1) + 2) = " << *(*(a + 1) + 2) << endl;

    // *(*(a + 2) + 0)
    // third row, first column
    // result = 4
    cout << "*(*(a + 2) + 0) = " << *(*(a + 2) + 0) << endl;

    // ---------------- FORMULA CHECK ----------------
    cout << "\n--- Formula a[i][j] = *(*(a + i) + j) ---" << endl;

    int i = 2, j = 0;

    // Using pointer formula instead of indexing
    cout << "a[2][0] using formula = " << *(*(a + i) + j) << endl;

    // ---------------- 1D POINTER CONCEPT ----------------
    cout << "\n--- 1D Pointer ---" << endl;

    // &a[0][0] → address of first element of matrix
    int *p = &a[0][0];

    cout << "p (base address of array) = " << p << endl;

    // *p → first element
    cout << "*p = " << *p << endl;

    // *(p + 4)
    // moves 4 elements forward in row-major order
    // 6 → 2 → 5 → 0 → 1
    cout << "*(p + 4) = " << *(p + 4)
         << " (row-major traversal)" << endl;

    return 0;
}