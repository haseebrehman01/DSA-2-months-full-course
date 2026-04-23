#include <iostream>
using namespace std;

// Function to display array
void display(int arr[], int n) {
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to display array after deletion
void displayAfterDeletion(int arr[], int n, int deletedValue) {
    cout << "Array elements after deletion of " << deletedValue << " are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Updated array size is: " << n << endl;
}

int main() {

    int arr[50] = {20, 40, 90, 70, 30};
    int n = 5;

    display(arr, n);

    cout << "Enter the position to delete (1-based index): ";
    int pos;
    cin >> pos;

    // 🔴 Step 1: Validate input first
    // This prevents accessing invalid memory locations
    if (pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    // 🔴 Step 2: Store the value that will be deleted
    // Convert position (1-based) to index (0-based)
    int deletedValue = arr[pos - 1];

    // 🔴 Step 3: Shift elements to the left
    // After deletion, we need to fill the empty space
    // by moving all elements one position to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];

        /*
        Dry Run Example:
        Array = [20, 40, 90, 70, 30]
        pos = 2 (delete 40)

        i = 1 → arr[1] = arr[2] → 40 becomes 90
        i = 2 → arr[2] = arr[3] → 90 becomes 70
        i = 3 → arr[3] = arr[4] → 70 becomes 30

        Final array in memory:
        [20, 90, 70, 30, 30]

        Note:
        The last element is duplicated, not garbage.
        */
    }

    // 🔴 Step 4: Decrease logical size of array
    // The actual memory remains the same,
    // but we consider one less element now
    n--;

    displayAfterDeletion(arr, n, deletedValue);

    return 0;
}