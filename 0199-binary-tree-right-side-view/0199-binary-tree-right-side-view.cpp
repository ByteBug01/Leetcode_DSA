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
//by BFS------------------------------------
    // vector<int> rightSideView(TreeNode* root) {
    //     if(root == NULL) return {}; //return empty vector

    //     vector<int> ans;

    //     queue<TreeNode*> que;
    //     que.push(root);


    //     while(!que.empty()){

    //         int n  = que.size();
    //         TreeNode* node = NULL;
            
    //         while(n--){
    //             node = que.front();
    //              que.pop();

    //             if(node -> left != NULL){
    //                 que.push(node->left);
    //             }

    //             if(node -> right != NULL){
    //                 que.push(node->right);
    //             }
    //         }
    //          ans.push_back(node->val);
    //     }

    //     return ans;
    // }
    //--------------------------------------------


void preorder(TreeNode* root, int level, vector<int>& ans){

    if(root == NULL) return;

    if(ans.size() < level){
        ans.push_back(root->val);
    }

    preorder(root->right, level+1, ans);
    preorder(root->left, level + 1, ans);
}

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        preorder( root, 1, ans);

        return ans;
    }
};