/*
Pattern: Two pointers
Mistake: I used the pattern "res = res + word1[i]" which
first creates a new string "res + word1[i]" and then appends 
it to res. But, the more efficient approach would be to use "+="
which directly appends "word1[i]".

Key idea: Walk word1 and word2 with pointers i and j, appending one
char from each per iteration until either string is exhausted. Then
append whatever's left of the other (its unconsumed tail).

Time: O(n+m), where n=len(word1) and m=len(word2)
Space: O(n+m)
*/


#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        res.reserve(word1.size() + word2.size());

        size_t i = 0, j = 0; 

        while (i < word1.size() && j < word2.size()) {
            res += word1[i++];
            res += word2[j++];
        }

        res += word1.substr(i);
        res += word2.substr(j);

        return res;

    }
};




int main(void) {
    Solution sol;


    string word1 = "abc", word2 = "xyz";
    string res1 = "axbycz";
    assert(sol.mergeAlternately(word1, word2) == res1);


    string w1 = "ab", w2 = "abbxxc";
    string res2 = "aabbbxxc";
    assert(sol.mergeAlternately(w1, w2) == res2);

    cout << "All test passed!\n";

    return 0;
}

