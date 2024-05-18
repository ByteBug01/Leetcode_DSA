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

 int solve(TreeNode* root, int &moves) {
        if(root == NULL) {
            return 0;
        }
        
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);
        
        int total_extra_coins = (l + r + root->val) - 1;
        
        moves += abs(l) + abs(r);
        
        return total_extra_coins;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;

 if(!root->left && !root->right) {
            return 0;
        }

        solve(root, moves);

        return moves;
    }
};