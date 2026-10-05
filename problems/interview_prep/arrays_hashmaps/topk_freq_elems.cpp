/* 
Time: O(n)
Space: O(n)
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freqs;

        for (int num: nums) {
            freqs[num]++;
        }


        vector<vector<int>> buckets(n+1);

        for (const auto& [num, freq]: freqs) {
            buckets[freq].push_back(num);
        }

        vector<int> res;
        for (int i = n; i >= 0 && k > 0; i--) {
            for (int num: buckets[i]) { 
                res.push_back(num);
                k--;
            }
        }

        return res;
    }
};