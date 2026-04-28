#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v = {1, 2, 3, 4};

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.resize(6);

    cout << "After resize: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    v.push_back(5);

    if(!v.empty()) {
        cout << "First element: " << v.front() << endl;
    }

    cout << "Element at index 2: " << v[2] << endl;

    v.insert(v.begin() + 2, 10);

    cout << "Last element: " << v.back() << endl;

    v.erase(v.end() - 2);

    cout << "After erase: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    v.clear();

    cout << "After clear, size: " << v.size() << endl;
    cout << "Capacity still: " << v.capacity() << endl;

    return 0;
}