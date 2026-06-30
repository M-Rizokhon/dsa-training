/*
Pattern: Hash map
Mistake: I solved the problem many times before, so no mistake. 
Key idea: Store number-index pairs in a hash map and find the indices
of two numbers that add up to target.

Time: O(n)
Space: O(n)

Note: The program must be compiled with C++20 because it uses 
unordered_map's "contains()" method.
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



