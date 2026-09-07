/*
Pattern: Binary Tree, Tree
Mistake: I manually swapped left and right children instead
of simply calling swap() method.
Key idea: Think recursively. Swap left and right children, and
recursively invert the left and right subtrees. Base case is
when node is nullptr, in which case, just return.
Time: O(n)
Space: O(1)
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) 
            return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
