/*
Pattern: Two pointers
Mistake: None, it's an easy problem
Key idea: Define two pointers, left and right pointing to the first
and last chars respectively. while left < right, skip if either
of them is non alphanumeric. Otherwise, convert both chars at 
indices left and right to lowercase and compare, if not equal, 
return false, else continue. At the end return true.
Time: O(n), where n=len(s)
Space: O(1)
*/


#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = static_cast<int>(s.length()) - 1;

        while (left < right) {
            if (!isalnum((unsigned char)s[left])) {
                left++;
                continue;
            }
            if (!isalnum((unsigned char)s[right])) {
                right--;
                continue;
            }

            if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right]))
                return false;
            
            left++;
            right--;
        }

        return true;
    }
};


int main(void) {
    Solution sol;

    string str1 = "Was it a car or a cat I saw?";
    assert(sol.isPalindrome(str1) == true);

    string str2 = "tab a cat";
    assert(sol.isPalindrome(str2) == false);


    cout << "All tests passed!\n";


    return 0;
}




