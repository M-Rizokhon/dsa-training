// Time: O(nlogp), where n=len(piles), p=max(piles)
// Space: O(1)


#include <vector>
#include <algorithm>
using namespace std;

/*
Very important: ceiling(a / b) = (a + b - 1) / b;
assuming integer division.
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxval = *max_element(piles.begin(), piles.end());
        long long minval = (maxval + h - 1) / h;

        while (minval < maxval) {
            int c =  (minval + maxval) / 2;
            int curr_h = 0;

            for (int pile: piles) {
                curr_h += (pile + c - 1) / c;
            }

            if (curr_h <= h) {
                maxval = c;
            } else {
                minval = c + 1;
            }

        }
        return minval;

    }
};