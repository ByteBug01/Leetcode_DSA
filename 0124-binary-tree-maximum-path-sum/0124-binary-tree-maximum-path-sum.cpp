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
int maxsum;

int solve(TreeNode* root){
    if(root == NULL) return 0;


    int l = solve(root->left);
    int r = solve(root->right);

    int niche_hi_ans_milgya = l + r + root->val;

    int koi_ek_acha_mila = max(l,r)  + root->val;

    int sirf_rootval_max_h = root->val;

    maxsum = max({maxsum, niche_hi_ans_milgya, koi_ek_acha_mila, sirf_rootval_max_h} );

    return max( koi_ek_acha_mila, sirf_rootval_max_h);
}

    int maxPathSum(TreeNode* root) {
       maxsum =  INT_MIN;

        solve(root);

        return maxsum;
    }
};