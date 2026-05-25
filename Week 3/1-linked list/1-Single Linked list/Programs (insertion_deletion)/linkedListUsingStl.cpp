#include <iostream>
#include <list>
using namespace std;

int main() {

    // Creating List
    list<int> myList;

    // Insert at Back
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);


    //10 , 20 , 30

    // Insert at Front
    myList.push_front(5);

    //5,10,20,30


    cout << "List Elements:" << endl;

    // Display List
    for (int value : myList) {
        cout << value << " ";//5,10,20,30
    }

    cout << endl;

    // Delete Front
    myList.pop_front();//10,20,30

    // Delete Back
    myList.pop_back();//10,20

    cout << "\nAfter Deletion:" << endl;

    for (int value : myList) {
        cout << value << " ";//10,20
    }

    cout << endl;

    // Front Element
    cout << "\nFront Element: " << myList.front() << endl;//10

    // Back Element
    cout << "Back Element: " << myList.back() << endl;//20

    // Size
    cout << "Size: " << myList.size() << endl;//2

    // Search Element
    int key = 20;
    bool found = false;//flag

    for (int value : myList) {

        if (value == key) {
            found = true;
            break;
        }

    
    }

    if (found) {
        cout << "Element Found" << endl;//found
    }
    else {
        cout << "Element Not Found" << endl;
    }

    // Reverse List
    myList.reverse();//20,10

    cout << "\nReverse List:" << endl;

    for (int value : myList) {
        cout << value << " ";//20,10
    }

    cout << endl;

    // Sort List
    myList.push_back(1);//20,10 ,1
    myList.push_back(100);//20,10 ,1,100
    myList.push_back(50);//20,10 ,1,100,50

    myList.sort();//1,10,20,50,100

    cout << "\nSorted List:" << endl;

    for (int value : myList) {
        cout << value << " ";//1,10,20,50,100
    }

    cout << endl;

    return 0;
}