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


    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> numset(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while(curr->next != NULL){
            if(numset.count(curr->next->val)){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }else{
                curr = curr->next;
            }
        }


        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};