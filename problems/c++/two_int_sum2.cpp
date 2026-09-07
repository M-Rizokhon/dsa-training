/*
Pattern: Two pointers
Mistake: No mistake, pretty straightforward algorithm.
Key idea: Use two pointers, l (left) and r (right) to find
the correct pair. 

Time: O(n)
Space: O(1)
*/

#include "libs.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        
        while (l < r) {
            int curr = numbers[l] + numbers[r];
            if (curr == target) 
                return vector<int>{l + 1, r + 1};
            else if (curr > target)
                r--;
            else 
                l++;
        }

        return vector<int>{-1, -1};
    }
};


int main(void) {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    int target1 = 3;   
    vector<int> res1 = {1, 2};
    assert(sol.twoSum(nums1, target1) == res1);

    cout << "OK\n";

    return 0;
}





