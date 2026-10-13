// Time: O(n)
// Space: O(1)
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minCost = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minCost);
            
            if (prices[i] < minCost)
                minCost = prices[i];
        }

        return profit;
    }
};

