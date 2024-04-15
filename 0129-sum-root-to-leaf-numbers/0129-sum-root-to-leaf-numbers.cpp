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
    
     bool isLeaf(TreeNode* root) {
        if(root->left || root->right) return 0;
        return 1;
    }
    
     int sumNumbers(TreeNode* root, int bf) {
        if(isLeaf(root)) return bf * 10 + root->val;
        int left = (root->left) ? sumNumbers(root->left, bf * 10 + root->val) : 0;
        int right = (root->right) ? sumNumbers(root->right, bf * 10 + root->val) : 0;
        return left + right;
    }
    
    int sumNumbers(TreeNode* root) {
         return sumNumbers(root, 0);
    }
};