// Time: O(n^2)
// Space: O(1)

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0)        // impossible to reach 0 from this
                break;
            
            else if (i > 0 && nums[i] == nums[i-1])     // skip duplicates 
                continue;
            
            
            int l = i + 1, r = n - 1;
            while (l < r) {
                int num = nums[i] + nums[l] + nums[r];

                if (num > 0) {
                    r--;
                } else if (num < 0) {
                    l++;
                } else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return res;
    }
};