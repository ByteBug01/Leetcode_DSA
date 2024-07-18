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
//     bool isCompleteTree(TreeNode* root) {
//         //use BFS

//          queue<TreeNode*> que;
        
//         que.push(root);
        
//         bool past = false; 
        
//         while(!que.empty()) {
//             TreeNode* node = que.front();
//             que.pop();
            
//             if(node == NULL) {
//                 past = true;
//             } else {
//                 if(past == true) {
//                     return false;
//                 }
                
//                 que.push(node->left);
//                 que.push(node->right);
//             }
//         }
        
//         return true;
//     }
// };


//---------------dfs---------------------------
class Solution {
public:

int countNodes(TreeNode* root){
    if(root == NULL) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool dfs(TreeNode* root, int i, int tot){
    if(root == NULL) return true;

    if(i > tot) return false;

    return dfs(root->left, 2*i, tot) && dfs(root->right, 2*i+1, tot);
}
    bool isCompleteTree(TreeNode* root) {
        int totNodes = countNodes(root);

        int i = 1;

        return dfs(root, 1, totNodes);
    }
};