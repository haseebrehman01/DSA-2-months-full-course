#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> arr, int n)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;//4
        
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 2) //4 > 3
        {
            return arr[i];
        }
    }
    cout << "No majority element found." << endl;
    return -1;
    }
}
int main()
{

    vector<int> arr = {5, 5, 5, 5, 5, 8, 7};//7/2 = 3 --> return value > 3
    int n = arr.size();

    cout << majorityElement(arr, n) << endl;
    return 0;



    // {7, 7, 1, 1, 1, 7, 7};
    // {1, 1, 1, 7, 7, 7, 7};

}