// Time: O(n) average/amortized
// Space: O(1)

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int elem: nums) {
            if (seen.count(elem)) 
                return true;
            seen.insert(elem);
        }
        return false;
    }
};

