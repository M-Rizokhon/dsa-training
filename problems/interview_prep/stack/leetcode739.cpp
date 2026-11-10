#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);
        stack<int> st;    // stores indices


        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temps[i] >= temps[st.top()]) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = st.top() - i;
            }
            st.push(i);            
        }

        return res;


    }
};