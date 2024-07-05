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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

         if (!head || !head->next || !head->next->next) {
            // Less than three nodes, can't have critical points
            return {-1, -1};
        }
        
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* next = curr->next;

int pos = 1;
vector<int> temp;

        while(next){
            if((curr->val < next->val && curr->val < prev->val)  || (curr->val > next->val && curr->val > prev->val) ){
                 temp.push_back(pos);
            }
            prev =  curr;
            curr =  next;
            next =  next->next;
            pos++;
        }


        if (temp.size() < 2) {
            return {-1, -1};
        }

        int maxDis = temp[temp.size() - 1] - temp[0]; //maxDis always the diff between first and last critical pos
        int minDis = INT_MAX;

     for(int i = 1; i<temp.size(); i++){
        minDis = min(minDis, temp[i] - temp[i-1]);
     }

  return {minDis, maxDis};
    }
};