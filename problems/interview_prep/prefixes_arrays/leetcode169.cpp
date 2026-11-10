// Time: O(n)
// Space: O(1)
#include <vector>
using namespace std;


/*
Majority element is an element that appears more than floor(n/2) times. 

Obvious solution is simple: 
    - use hash map to compute the frequencies of elements
    - return an element that has occured > floor(n/2) times
    Time: O(n) + O(n) = O(n), Space: O(n)

How about more space efficient solution? 
There is one algorithm to find it, called majority voter's or voter's problem or smth, can't
remember exactly tbh :)

nums = [5, 5, 1, 1, 4, 1, 4, 1, 1, 1]
floor(n/2) = 5. 1 appears 6 times, which is >5, so it's majority element.
count = 2
majority_elem = 1


we maintain two variables:
    - count -> number of times 
    - majority_num



*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority_num = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority_num) {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    majority_num = nums[i];
                    count = 1;
                }
            }
        }

        return majority_num;
    }
};