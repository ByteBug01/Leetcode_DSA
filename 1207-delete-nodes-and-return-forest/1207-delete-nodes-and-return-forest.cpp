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
// class Solution {
// public:
// TreeNode* deleteHelper(TreeNode* root, unordered_set<int> mpset, vector<TreeNode*> &ans){
//     if(root ==NULL) return NULL;

//     root->left = deleteHelper(root->left, mpset, ans);
//     root->right  = deleteHelper(root->right, mpset, ans);

//     if(mpset.find(root->val) != mpset.end()){
//         if(root -> left != NULL)
//         ans.push_back(root->left);

//         if(root->right != NULL)
//         ans.push_back(root->right);

//         return NULL;
//     }else{
//         return root;
//     }
// }

//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//       unordered_set<int> mpset;

//       vector<TreeNode*> ans;

//       deleteHelper(root, mpset, ans);

//       if(mpset.find(root->val) == mpset.end()){ //set m root nhi h
//             ans.push_back(root);
//       }  

//       return ans;
//     }
// };

class Solution {
public:
    TreeNode* deleteNodes(TreeNode* root, set<int> st, vector<TreeNode*>& result) {
        if(!root)
            return NULL;

            //dfs , exploring depth nodes first
        root->left  = deleteNodes(root->left , st, result); //left  se deleted nodes
        root->right = deleteNodes(root->right, st, result); //right se deleted nodes
        
        if(st.count(root->val)) { //if I have to delete this root, then put root->left and root->right in result
            if(root->left  != NULL)
                result.push_back(root->left);
            if(root->right != NULL)
                result.push_back(root->right);
            return NULL;
        }
        else
            return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(int i:to_delete)
            st.insert(i);
        
        vector<TreeNode*> result;
        deleteNodes(root, st, result); // <-- it will not consider root
        
        //So, check here if root is to be deleted or not
        if(!st.count(root->val)) {
            result.push_back(root);
        }
        return result;
    }
};
