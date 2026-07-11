/*
Pattern: Two pointers
Mistake: I forgot to handle an edge case when nums is empty
Key idea: Two-pointer overwrite — "k" marks the next write slot for 
elements != val, "i" scans forward. Copy-and-advance k on keep, 
skip on match. k = final count of kept elements.

Time: O(n), n = length(nums)
Space: O(1)
*/

#include "libs.h"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

