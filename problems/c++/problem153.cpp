/*
Pattern: Binary Search, Two Pointers
Mistake: I did not read the instructions carefully, so I
missed the part that said "every element in nums is unique".
That overcomplicated the problem.

Key idea: After rotation, the array is two sorted runs: a larger run
on the left and a smaller run on the right. The minimum is the first
element of the right run (the pivot). Find it with binary search.

Compare nums[mid] with nums[r]. The right endpoint always belongs to
the smaller run (or the array is fully sorted), so the comparison is
unambiguous:
  - nums[mid] < nums[r]: mid..r is sorted, so the minimum is at mid
    or to its left -> r = mid (keep mid as a candidate).
  - nums[mid] > nums[r]: mid is in the larger run, so the minimum is
    strictly right of mid -> l = mid + 1.
Loop while l < r. When they meet, nums[l] is the minimum.


Time: O(logn)
Space: O(1)
*/

#include "libs.h"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }

};


