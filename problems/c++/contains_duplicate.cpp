/*
Pattern: Array
Mistake: was first thinking about using hash map 
Key idea: use hash set to keep track of elements seen
Time: O(n)
Space: O(n) for "seen" hash set
Note: This program needs C++20 because it uses unordered_set::contains().
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int elem: nums) {
            if (seen.contains(elem)) 
                return true;
            seen.insert(elem);
        }
        return false;
    }
};



int main(void) {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 3};
    assert(sol.hasDuplicate(nums1) == true);

    vector<int> nums2 = {2, 3, 4, 5};
    assert(sol.hasDuplicate(nums2) == false);

    cout << "All tests passed.\n";

    return 0;
}