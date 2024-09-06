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
     unordered_set<int> sett(nums.begin(), nums.end());
     ListNode* dummy = new ListNode(-1);
     dummy->next = head;
     ListNode* curr = dummy;

     while(curr->next != NULL){
         if(sett.count(curr->next->val)){
            ListNode* tmp = curr->next;
            curr->next= curr->next->next;
            delete tmp;
         }else{
            curr = curr->next;
         }
     }
//  ListNode* result = dummy->next;
//         delete dummy;
//         return result;
return dummy->next;
    }
};