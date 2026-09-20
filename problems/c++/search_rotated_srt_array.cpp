/*
Pattern: Binary search
Key idea: A rotated sorted array is two sorted runs, nums[0:k) and nums[k:n).
Every element of the first run is >= nums[0]; every element of the second is < nums[0].
So the predicate (nums[i] >= nums[0]) looks like T T T F F F, and k is the first F.
Find k with a lower_bound-style binary search, then binary search each run.

Mistake: I first compared against nums[l] instead of nums[0]. The reference moved as l
moved, so the T/F pattern wasn't fixed and the search could skip the pivot (or loop forever
with l = c). The comparison point has to be a fixed reference.

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
            if (nums[c] >= nums[0])
                l = c + 1;
            else 
                r = c;
        }
        int k = l;

        int idx = bin_search(nums, target, 0, k);
        if (idx != -1)
            return idx;
        return bin_search(nums, target, k, nums.size());
        
    }



    // Find the index of target in nums[i:j] using bin search 
    int bin_search(vector<int>& nums, int target, int i, int j) {
        int l = i, r = j;

        while (l < r) {
            int c = (r + l) / 2;
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





