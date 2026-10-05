/*
Time: O(n)
Space: O(n)
*/


#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_prods(n, 1), suffix_prods(n, 1);

        // find prefix products
        for (int i = 1; i < n; i++) {
            prefix_prods[i] = prefix_prods[i-1] * nums[i-1];
        }

        // find suffix products
        for (int i=n-2; i >= 0; i--) {
            suffix_prods[i] = suffix_prods[i+1] * nums[i+1];
        }


        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[i] = prefix_prods[i] * suffix_prods[i];
        
        return res;
    }
};