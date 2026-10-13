// Time: O(n), where n=len(s2)
// Space: O(1)

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        if (k > n) return false;

        int s1_freqs[26] = {0}, s2_freqs[26] = {0};
        for (int j = 0; j < k; j++) {
            s1_freqs[s1[j] - 'a']++;
            s2_freqs[s2[j] - 'a']++;
        }

        for (int i = k; i < n; i++) {

            bool perm = true;
            for (int z = 0; z < 26; z++) {
                if (s1_freqs[z] != s2_freqs[z]) {
                    perm = false;
                    break;
                }
            }
            if (perm) return true;

            s2_freqs[s2[i - k] - 'a']--;
            s2_freqs[s2[i] - 'a']++;
        }

        for (int z = 0; z < 26; z++) {
            if (s1_freqs[z] != s2_freqs[z]) {
                return false;
            }
        }

        return true;
    }
};