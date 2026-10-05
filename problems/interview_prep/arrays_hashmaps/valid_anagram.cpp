// Time:  O(n), where n=length(s)=length(t)
// Space: O(1)

#include <iostream>
#include <string>
#include <vector>
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
        
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }
};