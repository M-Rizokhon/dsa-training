// Time: O(n)
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            best = max(best, curr);
        }

        return best;
    }
};