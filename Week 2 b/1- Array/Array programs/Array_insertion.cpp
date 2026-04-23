// #include <iostream>
// using namespace std;

// void display(int arr[] , int n){
//     cout << "Array elements are: ";
// for(int i = 0 ; i < n ; i++){
// cout << arr[i] << " " ;
// }
// }
// int main(){


// int arr[50] =  {2,3,6,8,9}  ;
// int n = 5;
// display(arr , n);

// cout << "Add an element at the end of the array: ";
// int element;//90
// cin >> element;//90
// arr[n] = element; // arr[5] = 90 ==> before {2,3,6,8,9} (5 elements) after {2,3,6,8,9,90} (6 elements) 
// n++;// n = 6
// display(arr , n);// {2,3,6,8,9,90} (6 elements) , 6

// }



// {30,40,20,90,70}
// {30,40,50,20,90,70}

#include <iostream>
using namespace std;

void display(int arr[], int n) {
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[50] = {30, 40, 20, 90, 70};
    int n = 5;

    display(arr, n);

    int pos, element;

    cout << "Enter the position to insert the element (1-based index): ";
    cin >> pos;

    cout << "Enter the element to insert: ";
    cin >> element;

    // 🔴 Step 1: Validate position
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    // 🔴 Step 2: Shift elements to the RIGHT
    // Start from end → move towards insertion point
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // 🔴 Step 3: Insert element at correct index
    arr[pos - 1] = element;

    // 🔴 Step 4: Increase logical size
    n++;

    display(arr, n);

    return 0;
}