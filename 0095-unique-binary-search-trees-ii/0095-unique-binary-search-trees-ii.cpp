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
    vector<TreeNode*> generateTrees(int n) {
        return recursion(1, n);
    }
    vector<TreeNode*> recursion(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>(1, nullptr);
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = recursion(start, i - 1);
            vector<TreeNode*> right = recursion(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    res.push_back(new TreeNode(i, left[j], right[k]));
                }
            }
        }
        return res;
    }
};