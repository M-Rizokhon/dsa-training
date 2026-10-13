// Time: O(logn)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int c = (l + r) / 2;

            if (nums[c] == target)
                return c;
            else if (nums[c] < target) {
                l = c + 1;
            } else {
                r = c;
            }
        }

        return -1;

    }
};