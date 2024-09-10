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

 int gcd(int a, int b){
    if(b == 0) return a;

    return (gcd(b, a%b));
 }

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* tmp = head;
     
        while( tmp->next != NULL){
            ListNode* newnode = new ListNode(gcd(tmp->val, tmp->next->val));

            newnode->next = tmp->next;
            tmp->next = newnode;
            tmp = newnode->next;

        }
        return head;
    }
};