#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_idx;

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            if (num_to_idx.count(comp)) {
                return vector<int>{num_to_idx[comp], i};
            }
            num_to_idx[nums[i]] = i;
        }
        return vector<int>{-1};
    }
};

