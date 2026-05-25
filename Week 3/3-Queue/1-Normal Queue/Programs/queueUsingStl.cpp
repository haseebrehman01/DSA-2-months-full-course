#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(10); // front
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;

    q.pop();

    cout << q.size() << endl;
     cout << q.back() << endl;
    // Print all elements
    // while(!q.empty()) {

    //     cout << q.front() << " ";

    //     q.pop();
    // }
 q.swap(20);
    return 0;
}