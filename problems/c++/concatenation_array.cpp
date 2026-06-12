/*
Pattern: Array
Mistake: I first used two loops while one loop suffices. 
Key idea: Copy each element to "ans" at index i and i+size(array)
Time: O(n)
Space: O(n) for the output array
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n * 2);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 1};
    vector<int> expected1 = {1, 2, 1, 1, 2, 1};
    assert(sol.getConcatenation(nums1) == expected1);

    vector<int> nums2 = {1, 3, 2, 1};
    vector<int> expected2 = {1, 3, 2, 1, 1, 3, 2, 1};
    assert(sol.getConcatenation(nums2) == expected2);

    cout << "All tests passed.\n";
    return 0;
}




