/*
Pattern: Hashing, Sorting, Arrays
Mistake: I did not initially used "auto", but I should have
because it's a good practice. "sortStr()" method had small
bugs, which I catched by testing it separately.

Key idea: Create a hash table "anagram_map", which stores 
sorted strings sorted_str as keys and vector of strings that are anagrams
to sorted_str. Build "anagram_map" from strs. 
Finally, build the result 2D vector of strings from anagram_map. 


Time: O(n * k), where n = length(strs), k = longest string
Space: O(n * k)

(NOTE: The program must be compiled with C++20)
*/

#include "libs.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;

        for (const auto& str: strs) {            
            string sorted_str = sortStr(str);
            anagram_map[sorted_str].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [key, val]: anagram_map) {
            res.push_back(val);
        }

        return res;
    }

    // Time: O(m), m = length(str)
    // Space: O(m)
    string sortStr(const string& str) {     
        vector<int> freq_table(26, 0);
        for (auto c: str) 
            freq_table[c - 'a']++;

        string res;
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq_table[i]; j++) 
                res += ('a' + i); 
        }
        return res;
    }
};



