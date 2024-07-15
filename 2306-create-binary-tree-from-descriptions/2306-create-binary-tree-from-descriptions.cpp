/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> mpset;
        unordered_map<int, TreeNode*> mp;

        for (auto& it : descriptions) {
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            mpset.insert(child);
        }

        for (auto& v : descriptions) {
            int p = v[0];
            if (mpset.find(p) == mpset.end()) {
                return mp[p];
            }
        }

        return NULL;
    }
};
