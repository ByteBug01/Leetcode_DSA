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
//thoda ajeeb approach hai,string m convert krk check kro map me
string solve(TreeNode* root, vector<TreeNode*>& ans,  unordered_map<string, int>& mp){
   if(root == NULL) return "N";

   string s = to_string(root->val) + "," + solve(root->left, ans, mp) + "," + 
                solve( root->right, ans, mp);

if(mp[s] == 1) ans.push_back(root);

mp[s]++;

return s;
}


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;

        vector<TreeNode*> ans;

        solve(root, ans, mp);

        return ans;
    }
};