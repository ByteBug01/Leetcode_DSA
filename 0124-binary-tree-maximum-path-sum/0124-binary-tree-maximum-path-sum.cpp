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
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int l = max(dfs(root->left),0);
        int r = max(dfs(root->right),0);
        ans = max(ans,root->val+l+r);
        return max(l+root->val,r+root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};