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
// class Solution {
// public:
// bool is1present(TreeNode* node){
//     if(node == NULL) return false;

//     if(node->val == 1) return true;

//     return (is1present(node->left) || is1present(node->right));
// }
//     TreeNode* pruneTree(TreeNode* root) {
//         if(root == NULL) return NULL;

//         if(!is1present(root->left)){
//             root->left = NULL;
//         }

//         if(!is1present(root->right)){
//             root->right = NULL;
//         }

//         pruneTree(root->left);
//         pruneTree(root->right);

//         if(root->left == NULL && root->right == NULL && root->val){
//             return NULL;
//         }

//         return root;
//     }
// };


class Solution {
public:
	//This is called for all node and hence Time : O(n^2)
    bool checkOne(TreeNode* root) {
        if(!root)
            return false;
        
        if(root->val == 1)
            return true;
        
        return checkOne(root->left) || checkOne(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        pruneTree(root->left);
        pruneTree(root->right);
        
        if(!checkOne(root->left))  root->left = NULL;
        if(!checkOne(root->right)) root->right = NULL;
        
        
        if(!root->left && !root->right && root->val == 0)
            return NULL;
        return root;
    }
};