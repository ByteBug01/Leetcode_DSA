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

void solve(TreeNode* left, TreeNode* right, int level){
   if(!left ||!right) return;

   if(level %2!= 0){
    swap(left->val, right->val);
   }

//see whose left and whoes right------------
//    solve(left->left, left->right, level+1);
//    solve(right->left, right->right, level+1);

   solve(left->left, right->right, level+1);
   solve(left->right, right->left, level+1);

}

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;
        // int level = 0;
        
//--------bfs ----------------------

        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){
        //    int size = q.size();
        //    vector<TreeNode*> nodes;


        //    for(int i =0; i<size; i++){
        //         TreeNode* node = q.front();
        //         q.pop();

        //         nodes.push_back(node);
                
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //    }

        //             if(level %2 != 0){ //reverse node at odd level

        //                         int l = 0, r = nodes.size()-1;
        //                             while(l<r){
        //                         swap(nodes[l]->val, nodes[r]->val);
        //                         l++;
        //                         r--;
        //                         }

        //             }
        // level++;

        // }



    //-------recursion------------------
    solve(root->left, root->right, 1);    

        return root;
    }
};

// Level 0:        [2]
// Level 1:    [3, 5] (odd level)
// Level 2:  [8, 13, 21, 34]



// Level 0:        [2]
// Level 1:    [5, 3] (reversed values)
// Level 2:  [8, 13, 21, 34]

