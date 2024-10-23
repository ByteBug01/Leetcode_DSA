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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        //TreeNode* root1 = new TreeNode(0);

        root->val  = 0;
     //   vector<TreeNode*> currlevel;

      while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            vector<TreeNode*> currentLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node);

                if (node->left) {
                    q.push(node->left);
                    levelSum += node->left->val;
                }
                if (node->right) {
                    q.push(node->right);
                    levelSum += node->right->val;
                }
            }

            for (TreeNode* node : currentLevel) {
                int siblingSum = 0;

                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) node->left->val = levelSum - siblingSum;
                if (node->right) node->right->val = levelSum - siblingSum;
            }
        }

        return root;
    }
};