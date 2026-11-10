// Time: O(n)
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;

/*
Naive approach:
Use in-place form of merge sort. 
It takes O(nlogn) time and O(1) space. 

I think, there exists a better/more efficient solution:
    O(n) time and O(1) space. 

Let's think.
move 0s as left as possible, move 2s as right as possible. 



Think about cases:
place l and r at positions where nums[l] != 0, nums[r] != 2
scan the loop, whenever you encounter non one, handle it. 



              l  r   
nums = [0, 0, 1, 1, 2, 2]
l = 2, r = 4
i = 3






nums = [2,0,1]


*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, r = nums.size() - 1;

        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                i++;
                l++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                i++;
            }
        }
    }
};