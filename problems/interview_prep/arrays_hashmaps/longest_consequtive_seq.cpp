// Time:  O(n)
// Space: O(n)
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int best = 0;

        for (int num: seen) {
            if (seen.count(num - 1)) {
                continue;
            }

            int len = 1;
            while (seen.count(num + len)) {
                len++;
            }

            best = max(best, len);
        }
        return best;

    }
};