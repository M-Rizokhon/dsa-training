// Time: O(logn)
// Space: O(1)


#include <vector>
using namespace std;


class Solution {
public:
    // run binary search on nums[i : j] (j exclusive)
    int binary_search(vector<int>& nums, int target, int i, int j) {
        while (i < j) {
            int c = (i + j) / 2;
            if (nums[c] == target)
                return c;
            else if (nums[c] < target) {
                i = c + 1;
            } else {
                j = c;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        // find the point that divides nums into 
        // two sorted subarrays
        
        int l = 0, r = nums.size();

        while (l < r) {
            int c = (l + r) / 2;

            if (nums[c] < nums[0]) {
                r = c;
            } else {
                l = c + 1;
            }
        }

        int k = l;

        int idx = binary_search(nums, target, 0, k);
        if (idx != -1)
            return idx;

        return binary_search(nums, target, k, nums.size());
    }
};

