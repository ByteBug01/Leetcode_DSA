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
// The middle element of the array becomes the root of the BST.
// Elements to the left of the middle element in the array will form the left subtree.
// Elements to the right of the middle element will form the right subtree.

TreeNode* bst(vector<int>& nums, int l, int r){
    if(l>r) return NULL;

     
     int mid = l + (r-l)/2;

     TreeNode* root = new TreeNode(nums[mid]);

     root->left = bst(nums, l, mid-1);
     root->right = bst(nums, mid+1, r);

     return root;

}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size()-1);
    }
};