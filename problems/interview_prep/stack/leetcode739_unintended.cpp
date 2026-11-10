// Time & Space: O(n)

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> temp_table(101, -1);
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            int temp = temps[i];
            int min_idx = -1;

            for (int t = temp + 1; t < 101; t++) {
                if (temp_table[t] != -1) {
                    min_idx = min_idx != -1 ? min(min_idx, temp_table[t]) : temp_table[t];
                }
            }

            if (min_idx != -1) {
                res[i] = min_idx - i;
            }

            temp_table[temp] = i;
        }

        return res;

    }
};