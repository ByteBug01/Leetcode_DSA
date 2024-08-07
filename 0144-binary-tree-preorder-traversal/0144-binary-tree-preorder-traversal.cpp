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
// void preorder(TreeNode*&root,vector<int>&pre){
//         if(root){
//             pre.push_back(root->val);
//             preorder(root->left,pre);
//             preorder(root->right,pre);
//         }
//     }

///iterative preorder traversal-------using stack
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> preorder;

         if(root == NULL) return preorder;

         stack<TreeNode*> st;
            st.push(root);

            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();

                preorder.push_back(node->val);

                if(node->right) st.push(node->right); //using stack so we first push node->right, in preorder

                if(node->left) st.push(node->left);

                
            }


            return preorder;
    }
};