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
    int maxdiff;
    
    void findMaxDiff1(TreeNode* root, TreeNode* child){
        if(root == NULL || child == NULL) return;
        
        maxdiff = max(maxdiff, abs(root->val - child->val));
        
        findMaxDiff1(root, child->left);
        findMaxDiff1(root, child->right);
        
    }
    
    void findMaxDiff2(TreeNode* root){
        if(root == NULL) return ;
        
        findMaxDiff1(root, root->left);
        findMaxDiff1(root, root->right);
        
        findMaxDiff2( root->left);
        findMaxDiff2( root->right);
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        maxdiff = -1;
        
        findMaxDiff2(root);
        
        return maxdiff;
    }
};