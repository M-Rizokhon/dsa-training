/*
Pattern: Prefix/Suffix
Mistake: No mistake, but need to be careful with prefix/suffix
edge cases, such as the prefix of the first element or 
the suffix of the last element. 
Key idea: For every element nums[i], precompute the products
of all elements before it (in prefixes) and after it (in suffixes).
Then: output[i] = prefix[i] * suffix[i]

Time: O(n)
Space: O(n)
*/
#include "libs.h"
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefs(n, 1), suffs(n, 1);

        // compute prefix products
        for (int i = 1; i < n; i++) 
            prefs[i] = prefs[i - 1] * nums[i - 1];

        // compute suffix products
        for (int i = n - 2; i >= 0; i--) 
            suffs[i] = suffs[i + 1] * nums[i + 1];

        
        vector<int> output(n);
        for (int i = 0; i < n; i++) 
            output[i] = prefs[i] * suffs[i];

        return output;
    }
};




int main(void) {
    Solution sol;

    vector<int> nums1 = {1, 2, 4, 6};
    vector<int> res1 = {48, 24, 12, 8};
    assert(sol.productExceptSelf(nums1) == res1);

    vector<int> nums2 = {-1, 0, 1, 2, 3};
    vector<int> res2 = {0, -6, 0, 0, 0};
    assert(sol.productExceptSelf(nums2) == res2);

    cout << "Everything OK\n";

    return 0;
}
