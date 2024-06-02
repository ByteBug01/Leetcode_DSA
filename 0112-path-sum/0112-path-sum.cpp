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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
  // sum in krenge node->values ka, but hum ye dekhenge ki target-(root->val) exist krta
  // h ki nai at the end of the leaf->value same hui then true otherwise false
        
        if(!root->left && !root->right){
            return targetSum == root->val;
        }

    bool left_sum = hasPathSum(root->left, targetSum - root->val);
    bool right_sum = hasPathSum(root->right, targetSum - root->val);

    return left_sum || right_sum;
    }
};