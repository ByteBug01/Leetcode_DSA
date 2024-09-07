/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true; // Linked list completely matched
        if (root == nullptr) return false; // End of the tree branch

        if (head->val == root->val) {
            // Continue checking the next node in the list with either left or right child in the tree
            return solve(head->next, root->left) || solve(head->next, root->right);
        }

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;

        // Check if current root matches or recursively check in the left and right subtrees
        return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
