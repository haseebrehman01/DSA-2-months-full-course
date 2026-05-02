// Problem 27 : Remove Element 
#include <iostream>
#include <vector>
using namespace std;

int removeOccurrence(vector<int>& arr , int val){
    int k = 0;
    for( int num : arr){
        if(num != val){
            arr[k] = num;
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> arr = {0,1,2,1,1,3,1};
    int value = 1;
    
    cout << "New size: " << removeOccurrence(arr ,value) << endl;
    cout << "Modified array: ";
    for(int i = 0; i < arr.size(); i++){
        cout  << arr[i] << " ";
    }
    cout << endl;

}