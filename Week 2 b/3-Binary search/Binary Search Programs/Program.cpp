// #include <iostream>
// #include <vector>
// using namespace std;

// int BinarySearch(const vector<int>& arr, int target){
//     int start = 0;
//     int end = arr.size() - 1;

//     while(start <= end){
//       int mid = start + (end-start) /2 ;//qka agar dono integer mai bhot batri value agai jesa 10000 aur woh bhi + horahai hun toh integer overflow hojayega

//         if( arr[mid] == target){
//             return mid;
//         }
//         else if(target > arr[mid]){
//             start = mid + 1;
//         }
//         else{
//             end = mid - 1;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr = {-2,0,1,2,4,5,6};
//     int target = -2;

//     cout << BinarySearch(arr, target) << endl;
// }

///////////////////////////////Binary serach if array is in descending order
//sirf right lefy dekho or uko dimmag mai dekhkar + - karo mid ko strt end  ka lya
// #include <iostream>
// #include <vector>
// using namespace std;

// int BinarySearch(const vector<int>& arr, int target){
//     int start = 0;
//     int end = arr.size() - 1;

//     while(start <= end){
//       int mid = start + (end-start) /2 ;//qka agar dono integer mai bhot batri value agai jesa 10000 aur woh bhi + horahai hun toh integer overflow hojayega

//         if( arr[mid] == target){
//             return mid;
//         }
//         else if(target > arr[mid]){
//             end = mid - 1;
//         }
//         else{
//             start = mid + 1;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr = {9,8,7,5,3,2,1};
//     int target = 2;

//     cout << BinarySearch(arr, target) << endl;
// }


///////////////////////////////Binary serach with recursion
// #include <iostream>
// #include <vector>
// using namespace std;

// int BinarySearch(const vector<int>& arr, int target , int start , int end){
//     if(start <= end){
//     int mid = start + (end-start) /2;

//     if(target == arr[mid]){
//     return mid ;
//     }
//     else if(target < arr[mid]){
//    return  BinarySearch( arr, target , start ,   mid -1);
//     }
//     else{
//         return  BinarySearch( arr, target ,  mid +1 ,  end );
//     }
// }
// else{
//     return -1;
// }
// }
// int main(){
//     vector<int> arr = {-2,0,1,2,4,5,6};
//     int target = 12;
  


//     cout << BinarySearch(arr, target , 0 , arr.size()-1) << endl;
//     return 0;
// }

///////////////////////Order-agnostic binary search
// Order-agnostic binary search means:

// 👉 You don’t know whether the array is sorted in ascending or descending order, but you still want to apply binary search.

// The trick is: first detect the order, then adjust the same binary search logic accordingly.
// #include <iostream>
// #include <vector>
// using namespace std;

// int orderAgnosticBinarySearch(const vector<int>& arr, int target) {
//     int start = 0;
//     int end = arr.size() - 1;

//     if (arr.empty()) return -1;

//     // Step 1: detect order
//     bool isAscending = arr[start] < arr[end];

//     // Step 2: binary search
//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (arr[mid] == target)
//             return mid;

//         if (isAscending) {
//             // normal binary search
//             if (target < arr[mid])
//                 end = mid - 1;
//             else
//                 start = mid + 1;
//         } else {
//             // reversed binary search
//             if (target > arr[mid])
//                 end = mid - 1;
//             else
//                 start = mid + 1;
//         }
//     }

//     return -1;
// }

// int main() {
//     vector<int> arr = {10, 7, 5, 3, 1}; // descending
//     int target = 5;

//     cout << orderAgnosticBinarySearch(arr, target) << endl;
// }
