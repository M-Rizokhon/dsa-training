/*
Time:  O(n * k)
Space: O(n * k)
n=number of strings, k=length of the longest string 
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;




class Solution {
public:
    string normalize(const string& str) {
        int freq[26] = {};
        for (char c : str) freq[c - 'a']++;

        string res;
        for (int i = 0; i < 26; i++) {
            res.append(freq[i], 'a' + i);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& str : strs) {
            groups[normalize(str)].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& [key, val] : groups) {
            res.push_back(std::move(val));
        }
        return res;
    }
};