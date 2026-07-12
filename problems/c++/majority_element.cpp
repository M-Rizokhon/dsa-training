/*
Pattern: Boyer-Moore algorithm (though Hashing can also be used)
Mistake: None, I've solved the problem before. 
Key idea: Maintain a candidate integer and its count. 
When we see the candidate, increment the count, else decrement it.
When count is 0, pick a new candidate. Since the majority element
appears more than half the time, it will survive the elimination 
process, and remain as the final candidate.


Time: O(n)
Space: O(1)
*/

#include "libs.h"
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        int count = 0;

        for (int num: nums) {
            if (count == 0) {
                res = num;
                count++;
            }
            else if (res == num) {
                count++;
            } else {
                count--;
            }
        }

        return res;
    }
};


int main(void) {
    Solution sol;


    vector<int> nums1 = {5, 5, 1, 1, 1, 5, 5};
    int res1 = 5;
    assert(sol.majorityElement(nums1) == res1);


    vector<int> nums2 = {2, 2, 2};
    int res2 = 2;
    assert(sol.majorityElement(nums2) == res2);

    cout << "All tests passed!\n";
    return 0;
}

