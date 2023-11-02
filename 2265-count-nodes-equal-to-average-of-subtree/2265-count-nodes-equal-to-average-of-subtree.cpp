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
    int match = 0;
    pair<int,int> subtreeCal(TreeNode* currentNode){
        if(currentNode == nullptr){
            return {0,0};
        }
        
        auto leftSubtree =  subtreeCal(currentNode-> left);
        auto rightSubtree = subtreeCal(currentNode->right);
            
            int sumOfValues = leftSubtree.first + rightSubtree.first + currentNode->val; ;
        int numberOfNodes = leftSubtree.second + rightSubtree.second + 1;
        
        if(numberOfNodes != 0 && sumOfValues/numberOfNodes == currentNode->val){
            match++;
        }
        
        return { sumOfValues, numberOfNodes};
    }
    int averageOfSubtree(TreeNode* root) {
        subtreeCal(root);
        return match;
    }
};