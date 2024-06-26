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

 // find the mid and make the tree
class Solution {
public:

void inorder(TreeNode* root, vector<int>& tree) {
        if (!root) return;

        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }

    TreeNode* solve(int l, int r, vector<int>& tree) {
        if (l > r) return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* new_root = new TreeNode(tree[mid]);

        new_root->left = solve(l, mid - 1, tree);
        new_root->right = solve(mid + 1, r, tree);

        return new_root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;

        inorder(root, tree);

        return solve(0, tree.size() - 1, tree);
    }
};