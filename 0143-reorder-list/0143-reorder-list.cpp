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
//     //APPROACH 1  TC: O(N) SC: O(1), Recursion used that's why O(n) (system stack used)
//     //for reversing from mid
//     ListNode* reverseLL(ListNode *head){
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
        
//         ListNode *last = reverseLL(head->next);
        
//         head->next->next = head;
//         head->next = NULL;
        
//         return last;
//     }
        
        
//     void reorderList(ListNode* head) {
//         //for finding mid node
        
//         ListNode* fast = head;
//         ListNode* slow = head;
        
//         while(fast && fast->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         ListNode* rev = reverseLL(slow);
        
//         //while loop for reordering
        
//         ListNode* curr = head;
        
//         while(rev->next != NULL){
//             ListNode* tempcurr = curr->next; //2
//             curr->next = rev; //4
            
//             ListNode *temprev = rev->next; //3
//             rev->next = tempcurr; //2
            
//             curr = tempcurr; //2
//             rev = temprev;  //3
//         }
//     }
// };

//we make our own stack----------------------------
// class Solution {
// public:

// void reorderList(ListNode* head) {
//    stack<ListNode*> st;

//    ListNode* curr = head;

//    while(curr){
//     st.push(curr);
//     curr = curr->next;
//    }

//    int k = st.size()/2; //mid

//     curr = head;

//    while(k--){

//     ListNode* last = st.top();
//     st.pop();
   
//     ListNode* temp = curr->next;

//     curr->next = last;
//     last->next = temp;
//     curr = temp;

//    }
//    curr->next = NULL;  
// }
// };

//------------------recursion--------------
//TC: o(n), SC: o(1)
class Solution {
public:

ListNode* curr;

void solve(ListNode* head){
    if(head == NULL ) return;

    solve(head->next);

    ListNode* temp = curr->next;

    if(temp == NULL){
        return;
    }else if(head == curr){
        head->next = NULL;
        return;
    }

    curr->next = head;
    head->next = (temp == head)? NULL: temp;

    curr = temp;
}

void reorderList(ListNode* head) {
  curr = head;
  solve(head);
}
};
