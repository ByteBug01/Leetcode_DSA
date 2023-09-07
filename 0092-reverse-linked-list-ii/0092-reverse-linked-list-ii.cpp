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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> s;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int le = left;
        while(--left){  
            temp1 = temp1->next;
        }
        while(--right){  
            temp2 = temp2->next;
        }
        while(temp1 != temp2->next){  
            s.push(temp1->val);
            temp1 = temp1->next;
        }
        temp1 = head;
        while(--le){   
            temp1 = temp1->next;
        }
        while(s.size()){   
            temp1->val = s.top();
            temp1 = temp1->next;
            s.pop();
        }
        return head;
    }
};