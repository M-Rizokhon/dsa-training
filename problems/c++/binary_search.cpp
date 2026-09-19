/*
Pattern: Binary Search
Mistake: I set while condition to "l <= r" which creates an infinite loop, "l < r" is enough.
Key idea: A simple iterative binary search algorithm.

Time: O(logn)
Space: O(1)
*/

#include "libs.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int c = (l + r) / 2;
            if (nums[c] == target) 
                return c;
            else if (nums[c] > target)
                r = c;
            else 
                l = c + 1;
        }
        return -1;

    }
};



int main() {
    Solution sol;

    vector<int> nums1 = {-1,0,3,5,9,12};
    int target1 = 9;
    assert(sol.search(nums1, target1) == 4);

    vector<int> nums2 = {-1,0,3,5,9,12};
    int target2 = 2;
    assert(sol.search(nums2, target2) == -1);

    cout << "Everything is OK\n";



}