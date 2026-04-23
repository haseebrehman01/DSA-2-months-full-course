// This program demonstrates how to traverse an array in C++. It allows the user to input the size of the array and its elements, and then it prints the elements of the array. 
#include <iostream>
#include <vector>
using namespace std;

void inputarr(vector<int>& arr, int n)
{
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}
void printArr(vector<int>& arr, int n)
{
    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

vector<int> arr(n);

    inputarr(arr, n);
    printArr(arr, n);

    return 0;
}