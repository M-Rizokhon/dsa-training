/*
Pattern: Hash map using array
Mistake: I first tried using a unordered_map hash map,
but using array is cleaner and more efficient

Key idea: count the frequencies of both strings and compare
Time: O(n), where n is size of "s" or "t"
Space: O(1)
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> freq(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int elem: freq)
            if (elem != 0)
                return false;
        
        return true;
    }
};


int main(void) {
    Solution sol;

    string s1 = "racecar", t1 = "carrace";
    assert(sol.isAnagram(s1, t1) == true);

    string s2 = "jar", t2 = "jam";
    assert(sol.isAnagram(s2, t2) == false);

    cout << "All tests passed.\n";

    return 0;
}

