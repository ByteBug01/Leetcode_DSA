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
// class Solution {
// public:
    
//     bool isPalindrome(ListNode* head) {
//          vector<int> vals = {};
//         while (head != NULL) {
//             vals.push_back(head->val);
//             head = head->next;
//         }

//         // check if it's palindrome
//         int n = vals.size();
//         for (int i = 0; i < n / 2; i++) {
//             if (vals[i] != vals[n - i - 1])
//                 return false;
//         }

//         return true;
//     }
// };


// ----------------bruteforce using stack----------------------
// class Solution {
// public:

// // TC: o(2n), SC: o(n)
//     bool isPalindrome(ListNode* head) {
//             stack<int> st;

//             ListNode* temp = head;

//             while(temp != NULL){
//                 st.push(temp->val);
//                 temp= temp->next;
//             }

//             temp = head;

//             while(temp != NULL){
//                 if(temp->val != st.top()){
//                     return false;
//                 }

//                 st.pop();
//                 temp = temp->next;
//             }


//             return true;
//     }
// };

//--------most optimal---------------
class Solution {
public:

ListNode* curr;

bool recur(ListNode* head){
    if(! head) {
        return true;
    }

    bool ans = recur(head->next);

    if(head->val != curr->val){
        return false;
    }

    curr = curr->next;

    return ans;
}

    bool isPalindrome(ListNode* head) {
        curr = head;
       return recur(head);
    }
};