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
class Solution {
public:
    //APPROACH 1
    //for reversing from mid
    ListNode* reverseLL(ListNode *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *last = reverseLL(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return last;
    }
        
        
    void reorderList(ListNode* head) {
        //for finding mid node
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* rev = reverseLL(slow);
        
        //while loop for reordering
        
        ListNode* curr = head;
        
        while(rev->next != NULL){
            ListNode* tempcurr = curr->next; //2
            curr->next = rev; //4
            
            ListNode *temprev = rev->next; //3
            rev->next = tempcurr; //2
            
            curr = tempcurr; //2
            rev = temprev;  //3
        }
    }
};