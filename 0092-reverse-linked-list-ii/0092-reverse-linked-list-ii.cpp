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
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         stack<int> s;
//         ListNode* temp1 = head;
//         ListNode* temp2 = head;
//         int le = left;
//         while(--left){  
//             temp1 = temp1->next;
//         }
//         while(--right){  
//             temp2 = temp2->next;
//         }
//         while(temp1 != temp2->next){  
//             s.push(temp1->val);
//             temp1 = temp1->next;
//         }
//         temp1 = head;
//         while(--le){   
//             temp1 = temp1->next;
//         }
//         while(s.size()){   
//             temp1->val = s.top();
//             temp1 = temp1->next;
//             s.pop();
//         }
//         return head;
//     }
// };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        ListNode* prev = dummy;

        for(int i =  1; i<left; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 1; i<= right-left; i++){
            ListNode* temp =  prev->next; //temp = b

            prev->next = curr->next; // a->next = c
            curr->next = curr->next->next; // b->next = c->next //d

            prev->next->next  = temp; // c->next  = b
        }

        return dummy->next;
    }
};