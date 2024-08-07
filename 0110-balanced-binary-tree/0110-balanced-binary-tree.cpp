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

// we do post order traversal which is done in a bottom up fashion , at the same time we find 
// the height of bottom subtrees is balanced or not thereby eliminating the unneccessay recursion calls 
   
   int postTraverse(TreeNode* root){
    if(root == NULL) return 0;

    int left = postTraverse(root->left);

    if(left == -1) return -1;


    int right = postTraverse(root->right);

    if(right == -1) return -1;

    if(abs(left - right) > 1) return -1;

    return max(postTraverse(root->left), postTraverse(root->right)) + 1;

   }
   
   
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return (postTraverse(root) == -1)? 0: 1;
        
    }
   
};