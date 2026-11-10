#include <vector>
using namespace std;

// version 1
// use extra space
// Time: O(n); Space: O(n)
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;
//         vector<int> left_part(n - k), right_part(k);

//         // extract left part
//         for (int i = 0; i < n - k; i++) {
//             left_part[i] = nums[i];
//         }

//         // extract right part
//         for (int i = n - k; i < n; i++) {
//             right_part[i - (n - k)] = nums[i];
//         }

        
//         // place elements back
//         for (int j = 0; j < k; j++) {
//             nums[j] = right_part[j];
//         }

//         for (int j = 0; j < n - k; j++) {
//             nums[j + k] = left_part[j];
//         }

//     }
// };




// version 2
// Time: O(n); Space: O(1)
class Solution {
public:
    // reverse nums[i:j + 1]
    void reverse(vector<int>& nums, int i, int j) {
        if (j - i < 1) return;

        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // reverse the array
        reverse(nums, 0, n - 1);

        // reverse two parts separately
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);

    }
};




