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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        

        priority_queue<long long> pq;

        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            while(size--) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            }

            pq.push(sum);
            }

if(pq.size() < k) return -1;

for(int i=1; i<k; i++) pq.pop();


return pq.top();
    }
};