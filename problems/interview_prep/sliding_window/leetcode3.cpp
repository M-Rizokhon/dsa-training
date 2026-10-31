// Time: O(n)
// Space: O(1)

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;

        vector<int> char_freq(100, 0);
        int max_length = 0;
        int left = 0, right = 0;

        while (right < s.length()) {
            char c = s[right];
            char_freq[c - ' ']++;

            if (char_freq[c - ' '] != 1) {
                while (s[left] != c) {
                    char_freq[s[left] - ' ']--;
                    left++;
                }
                char_freq[s[left] - ' ']--;
                left++;                
            }
            max_length = max(max_length, right - left + 1);
            right++;
        }

        max_length = max(max_length, right - left);

        return max_length;
    }
};