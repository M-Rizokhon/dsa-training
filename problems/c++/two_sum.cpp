/*
Pattern: Hash map
Mistake: I solved the problem many times before, so no mistake. 
Key idea: Store number-index pairs in a hash map and find the indices
of two numbers that add up to target.

Time: O(n)
Space: O(n)

Note: The program must be compiled with C++20 because it uses 
unordered_map's "contains()" method.
*/

#include <iostream>
#include <vector> 
#include <unordered_map>
#include <cassert>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;  // store num-index pairs

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indexMap.contains(diff))
                return vector<int> {indexMap[diff], i};
            indexMap[nums[i]] = i;
        }

    }
};



int main(void) {
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 6};
    int target = 7;
    vector<int> answer1 = {0, 1};
    assert(sol.twoSum(nums1, target) == answer1);

    vector<int> nums2 = {5, 1, 7, 3, 6, 8, 0};
    target = 15;
    vector<int> answer2 = {2, 5};
    assert(sol.twoSum(nums2, target) == answer2);

    cout << "All Tests Passed!\n";


    return 0;
}



