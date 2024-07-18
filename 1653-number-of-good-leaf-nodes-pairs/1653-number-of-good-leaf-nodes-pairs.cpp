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

void mkGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode* , vector<TreeNode*>> &adj
            ,unordered_set<TreeNode*> & st ){
                if(root == NULL) return;

                if(!root->left && !root->right){
                    st.insert(root);
                }
                
                if(prev !=  NULL){
                    adj[root].push_back(prev);
                    adj[prev].push_back(root);
                }

                mkGraph(root->left, root, adj, st );
                mkGraph(root->right, root, adj, st);

            }

int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode* , vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        mkGraph(root, NULL, adj, st);

        int ans = 0;

        for(auto &leaf: st){
           queue<TreeNode*> q;
           q.push(leaf);

           unordered_set<TreeNode*> visited;
            visited.insert(leaf);
            
            for(int level = 0; level <= distance; level++){
                int size = q.size();

                while(size--){
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr != leaf && st.count(curr)){
                        ans++;
                    }

                    for(auto & ngbr : adj[curr]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }

return ans/2;

    }
};