// =====================================================
// BRUTE FORCE APPROACH (O(n^2))
// =====================================================
// Idea: Compare every element with every other element
// If any duplicate pair is found → return true
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // Start j from i+1 to avoid rechecking previous pairs
            // and to prevent comparing an element with itself
            for (int j = i + 1; j < nums.size(); j++)
            {
                // If same value found at different indices → duplicate exists
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }

        // No duplicates found after checking all pairs
        return false;
    }
};

int main()
{
    Solution obj;

    // Test input
    vector<int> nums = {1, 2, 3, 2};

    // Function call
    bool result = obj.containsDuplicate(nums);

    // Output result
    if (result)
    {
        cout << "true" << endl;  // duplicate exists
    }
    else
    {
        cout << "false" << endl; // no duplicates
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // Step 1: Sort the array
        // After sorting, equal elements will come next to each other
        sort(nums.begin(), nums.end()); 
        // Time complexity: O(n log n)

        // Step 2: Check adjacent elements for duplicates
        for (int i = 1; i < nums.size(); i++)
        {
            // If current element is same as previous → duplicate found
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }

        // No duplicates found in entire array
        return false;
    }
};

int main()
{
    Solution obj;

    // Test input
    vector<int> nums = {1, 2, 3};

    // Function call
    bool result = obj.containsDuplicate(nums);

    // Output result
    if (result)
    {
        cout << "true" << endl;  // duplicate exists
    }
    else
    {
        cout << "false" << endl; // no duplicates
    }

    return 0;
}

// hashing approach to check for duplicates in the vector