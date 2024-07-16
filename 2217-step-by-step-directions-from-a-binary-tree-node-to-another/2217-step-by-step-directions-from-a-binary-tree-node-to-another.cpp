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
TreeNode* LCA(TreeNode* root, int s, int d){
    if(root==NULL) return NULL;

    if(root->val == s || root->val == d){
        return root;
    }

    TreeNode* l = LCA(root->left, s, d);
    TreeNode* r = LCA(root->right, s, d);


    if(l && r) return root;

    return l ?l:r;
}

bool findPath(TreeNode* lca, int goal, string& res){
    if(lca==NULL) return false;

    if(lca->val==goal) return true;

    res.push_back('L');
    if(findPath(lca->left, goal, res) == true){
        return true;
    }

    res.pop_back();

 res.push_back('R');
    if(findPath(lca->right, goal, res) == true){
        return true;
    }
    res.pop_back();

    return false;
}


    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);

        string lcaToSrc = "";
        string lcaToDes = "";


        findPath(lca, startValue, lcaToSrc);
        findPath(lca, destValue, lcaToDes);

        string ans = "";

        for(int i = 0; i<lcaToSrc.length(); i++){
            ans += "U";
        }

        ans += lcaToDes;

        return ans;
    }
};