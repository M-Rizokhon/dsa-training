// #include <iostream>
// #include <stack>
// #include <cassert>
// #include <string>

// class Solution {
// public:
//     bool isValid(std::string brackets) {
//         std::stack<char> st;
//         for (char &c: brackets) {
//             if (c == '(' || c == '[' || c == '{') {
//                 st.push(c);
//             } else {
//                 if (st.empty()) {
//                     return false;
//                 }

//                 if ((c == ']' && st.top() != '[') ||
//                     (c == '}' && st.top() != '{') ||
//                     (c == ')' && st.top() != '(')) {
//                     return false;
//                 }
//                 st.pop();
//             }
//         }

//         if (!st.empty()) return false;

//         return true;
//     }
// };

// int main() {
//     Solution sol;

//     auto check = [&](std::string s, bool expected) {
//         bool got = sol.isValid(s);
//         if (got != expected) {
//             std::cerr << "FAIL: \"" << s << "\" expected "
//                       << expected << " got " << got << "\n";
//         }
//         assert(got == expected);
//     };

//     // Basic valid
//     check("()", true);
//     check("[]", true);
//     check("{}", true);
//     check("()[]{}", true);

//     // Nested valid
//     check("{[]}", true);
//     check("({[]})", true);
//     check("([{}])", true);
//     check("{[()]}", true);
//     check("(((())))", true);
//     check("[({})]", true);
//     check("{()}[{}]", true);

//     // Mismatched types
//     check("(]", false);
//     check("([)]", false);
//     check("{[}]", false);
//     check("(}", false);

//     // Only openers (leftover on stack)
//     check("(", false);
//     check("((", false);
//     check("({[", false);
//     check("(()", false);

//     // Only closers / closer with empty stack
//     check(")", false);
//     check("]", false);
//     check("}}", false);
//     check("())", false);
//     check(")(", false);
//     check("()]", false);

//     // Edge case: empty string (vacuously valid)
//     check("", true);

//     // Long inputs
//     check(std::string(10000, '(') + std::string(10000, ')'), true);
//     check(std::string(10000, '(') + std::string(9999, ')'), false);
//     {
//         std::string s;
//         for (int i = 0; i < 5000; ++i) s += "{[()]}";
//         check(s, true);
//     }

//     std::cout << "All tests passed\n";
//     return 0;
// }



























// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <cassert>
// using namespace std;

// /*
// nums = [-5, -4, -2, 0, 1, 2, 3, 4, 5]



// */

// class Solution {
// public:
//     vector<int> squareSort(vector<int> nums) {
//         vector<int> res(nums.size());
//         int l = 0, r = nums.size() - 1;
//         int i = nums.size() - 1;
//         while (l <= r) {
//             if (abs(nums[l]) > abs(nums[r])) {
//                 res[i] = nums[l] * nums[l];
//                 l++;
//             } else {
//                 res[i] = nums[r] * nums[r];
//                 r--;
//             }
//             i--;
//         }


//         return res;
//     }
// };



// int main() {
//     Solution sol;

//     auto check = [&](vector<int> input, vector<int> expected) {
//         vector<int> got = sol.squareSort(input);
//         if (got != expected) {
//             cerr << "FAIL: input {";
//             for (int x : input) cerr << x << " ";
//             cerr << "}\n  expected {";
//             for (int x : expected) cerr << x << " ";
//             cerr << "}\n  got      {";
//             for (int x : got) cerr << x << " ";
//             cerr << "}\n";
//         }
//         assert(got == expected);
//     };

//     // Classic examples
//     check({-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100});
//     check({-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121});

//     // Empty and single element
//     check({}, {});
//     check({0}, {0});
//     check({5}, {25});
//     check({-5}, {25});

//     // All non-negative / all negative
//     check({1, 2, 3}, {1, 4, 9});
//     check({0, 1, 2, 3, 4, 5}, {0, 1, 4, 9, 16, 25});
//     check({-3, -2, -1}, {1, 4, 9});
//     check({-6, -5, -4, -3, -2, -1}, {1, 4, 9, 16, 25, 36});

//     // Duplicates
//     check({-2, -2, -2}, {4, 4, 4});
//     check({0, 0, 0}, {0, 0, 0});
//     check({-3, -3, 3, 3}, {9, 9, 9, 9});

//     // Negative and positive with same absolute value
//     check({-3, 3}, {9, 9});
//     check({-1, 0, 1}, {0, 1, 1});
//     check({-5, -3, 0, 3, 5}, {0, 9, 9, 25, 25});

//     // Large values (10^4 squared = 10^8, still fits in int)
//     check({-10000, -5000, 0, 5000, 10000},
//           {0, 25000000, 25000000, 100000000, 100000000});

//     // Larger input vs. brute-force reference
//     {
//         vector<int> input;
//         for (int i = -5000; i < 5000; ++i) input.push_back(i);
//         vector<int> expected;
//         for (int x : input) expected.push_back(x * x);
//         sort(expected.begin(), expected.end());
//         check(input, expected);
//     }

//     cout << "All tests passed\n";
//     return 0;
// }


































// #include <cassert>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <stack>
// using namespace std;

// /* 
// s = "azzzabbba", k = 3

// stack = {}




// */

// class Solution {
// public:
//     string solveProb(string s, int k) {
//         stack<pair<char, int>> st;

//         for (char c: s) {
//             if (st.empty()) {
//                 st.push({c, 1});
//             } else {
//                 if (c == st.top().first) {
//                     st.top().second++;
//                 }
//                 else {
//                     st.push({c, 1});
//                 }
//             }


//             if (st.top().second == k) {
//                 st.pop();
//             }
//         }

//         string tmp = "";
//         while (!st.empty()) {
//             for (int i = 0; i < st.top().second; i++) {
//                 tmp += st.top().first;
//             }
//             st.pop();
//         }

//         string actual_res;
//         for (int j = tmp.size() - 1; j >=0 ; j--) {
//             actual_res += tmp[j];
//         }

//         return actual_res;

        
        
//     }
// };




// struct Case { string s; int k; string expected; };

// int main() {
//     Solution sol;
//     vector<Case> tests = {
//         {"", 2, ""},
//         {"a", 2, "a"},
//         {"abcd", 2, "abcd"},
//         {"aab", 5, "aab"},
//         {"aaa", 2, "a"},
//         {"aaaa", 2, ""},
//         {"aaabbb", 3, ""},
//         {"abc", 1, ""},
//         {"aabbaa", 2, ""},
//         {"abbac", 2, "c"},
//         {"abbbaaa", 3, "a"},
//         {"azzzabbba", 3, ""},
//         {"deeedbbcccbdaa", 3, "aa"},
//         {"pbbcggttciiippooaais", 2, "ps"},
//         {string(100000, 'a'), 2, ""},
//         {string(100000, 'a'), 100000, ""},
//     };

//     for (size_t i = 0; i < tests.size(); i++) {
//         string got = sol.solveProb(tests[i].s, tests[i].k);
//         if (got != tests[i].expected) {
//             cout << "FAIL #" << i + 1 << ": expected \"" << tests[i].expected
//                  << "\", got \"" << got << "\"\n";
//         } else {
//             cout << "PASS #" << i + 1 << "\n";
//         }
//     }
// }





















#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twosumSorted(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                return {l + 1, r + 1};
            }

            else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }

        return {-1, -1};
    }

};
