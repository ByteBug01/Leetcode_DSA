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

void dfs(TreeNode* root, vector<string> & ans, string path){
 if (root == NULL) return;
 
   path += to_string(root->val);

    if(root->left == NULL && root->right == NULL){
           ans.push_back(path);
    }else{

    dfs(root->left, ans, path+ "->");
      dfs(root->right, ans, path+ "->");
    }

}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, ans, "");
        return ans;
    }
};

//dfs work kaise krra?
// isme backtrack hora ki ni?
//har ek path definitely lead to end or leaf node tbhi we are not poping out any node in between