/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

// Bruteforce------------------------------
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int> mp;
        
        ListNode* temp = head;

        while(temp != NULL){

            if(mp[temp] != 0){ // check if temp has been encountered again
                return temp; //  A loop is detected hence return temp
            }

            mp[temp] = 1; 
            temp = temp->next;
        }

        return NULL;
    }
};