// Time: O(logn)
// Space: O(1)


#include <vector>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int c = (l + r) / 2;

            if (nums[c] > nums[r]) {
                l = c + 1;
            } else {
                r = c;
            }
        }

        return nums[l];
    }
};
