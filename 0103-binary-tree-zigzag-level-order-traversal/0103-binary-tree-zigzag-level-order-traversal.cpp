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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // vector<vector<int>> zigzag;

        // if(root == NULL) return zigzag;

        // queue<TreeNode*> que;
        // que.push(root);

        // bool flag = false; //1st level L to R

        // while(!que.empty()){
        //     vector<int> level;
        //     stack<int> reversest;

        //     for(int  i  =0; i<que.size(); i++){
        //         TreeNode * node = que.front();
        //         que.pop();

        //         if(flag){
        //             reversest.push(node->val);
        //         }else{
        //             level.push_back(node->val);}


        //             if(node->left!= NULL) que.push(node->left);
        //             if(node->right!= NULL) que.push(node->right);
                
        //     }

        //         flag = !flag;

        //         while(!reversest.empty()){
        //             level.push_back(reversest.top());
        //             reversest.pop();
        //         }
            
        //     zigzag.push_back(level);
        // }
        // return zigzag;

          vector<vector<int>> zigzag;

        if (!root) return zigzag;

        queue<TreeNode*> que;
        que.push(root);

        bool flag = false;

        while (!que.empty()) {
            int size = que.size();
            vector<int> level(size); 

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                int index = flag ? size - i - 1 : i; // Determine the index based on flag

                level[index] = node->val;

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            zigzag.push_back(level);
            flag = !flag; 
        }
        return zigzag;
    }
};