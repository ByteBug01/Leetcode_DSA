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
// void sum(TreeNode* root, int l, int h , vector<int>& s){
//     if(root==NULL){
//         return;
//     }
//     if(root->val>=l && root->val<=h){
//         s.push_back(root->val);
//     }
//     sum(root->left, l, h, s);
//     sum(root->right, l, h, s);
// }

    
    


    int rangeSumBST(TreeNode* root, int low, int high) {
        // vector<int> s;
        // sum(root, low, high, s);
        // int sum=0;
        // for(int i=0; i<s.size(); i++){
        //     sum+=s[i];
        // }
        // return sum;
        
        if(root == NULL)  return 0;
        int sum =0;
        
        if(root->val >= low && root->val <= high){
            sum = root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        if(root->val < low){
           sum += rangeSumBST(root->right, low, high);
        }
        
        
        if(root->val> high){
            sum += rangeSumBST(root->left, low, high);
        }
        
        return sum;
    }
};