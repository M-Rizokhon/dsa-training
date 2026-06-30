/*
Pattern: Two pointers
Mistake: None, it's an easy problem. 
Key idea: Walk i from 0 to n/2, and at each step, swap s[i]
and its mirror position s[n-i-1]. This is equivalent to having a left pointer
start at 0 and a right pointer start at n-1, moving toward each other —
here the right index is just derived from i instead of tracked separately.


Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector> 
#include <cassert>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(), i;
        for (i = 0; i < n / 2; i++) {
            char temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }
    }
};



int main(void) {
    Solution sol;

    vector<char> arr1 = {'a', 'b', 'c', 'd'};
    vector<char> answer1 = {'d', 'c', 'b', 'a'};
    sol.reverseString(arr1);
    assert(arr1 == answer1);

    vector<char> arr2 = {'1', '2', '3'};
    vector<char> answer2 = {'3', '2', '1'};
    sol.reverseString(arr2);
    assert(arr2 == answer2);

    vector<char> arr3 = {'a'};
    vector<char> answer3 = {'a'};
    sol.reverseString(arr3);
    assert(arr3 == answer3);

    cout << "All Tests Passed!\n";


    return 0;
}



