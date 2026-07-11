/*
Pattern: Vertical scanning
Mistake: None
Key idea:  Fix a column index i, and compare the character at that
column across all strings simultaneously. Stop as soon as
a mismatch is found, or once i reaches the shortest
string's length (can't have a longer common prefix than that).
Time: O(n * m), where n=len(strs), m=shortest string's length
Space: O(m)
*/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = strs[0].length();

        // find the length of the shortest string
        for (const string& s: strs) {
            if (s.length() < min_length) 
                min_length = s.length();
        }


        string res = "";
        for (int i = 0; i < min_length; i++) {

            // check if char at index i exists in each string
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j - 1][i] != strs[j][i])
                    return res;
            }

            res = res + strs[0][i];
        }

        return res;
    }
};



int main(void) {
    Solution sol;

    vector<string> strs1 = {"bat", "bag", "bank", "band"};
    string res1 = "ba";
    assert(sol.longestCommonPrefix(strs1) == res1);

    vector<string> strs2 = {"neet", "feet"};
    string res2 = "";
    assert(sol.longestCommonPrefix(strs2) == res2);

    vector<string> strs3 = {"dance", "dag", "danger", "damage"};
    string res3 = "da";
    assert(sol.longestCommonPrefix(strs3) == res3);


    cout << "All tests passed!\n";
    return 0;
}

