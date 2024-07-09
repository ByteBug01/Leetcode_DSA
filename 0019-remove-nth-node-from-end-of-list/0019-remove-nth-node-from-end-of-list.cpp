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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // if(head == NULL){
        //     return NULL;
        // }
        
        
        // this is brutforce...........
//         ListNode *temp = head;
//         int cnt = 0;
        
//         while(temp != NULL){
//            temp =  temp->next;
//             cnt++;
//         }
        
//        int x = cnt- n;
        
//         if(x == 0 ){
//            return head-> next;
//         }
        
//         ListNode *prev ;
//         temp  = head;
        
//         for(int i  = 0 ;  i < x ;  i++){
//             prev = temp;
//             temp = temp->next;  
//         }
        
//         prev -> next = temp->next;
        
//         delete temp;
        
        
//         return head;
        
        
        // now this is optimised approach...with fast and slow pointer
        
//         ListNode * fast =  head;
//         ListNode * slow =  head;
        
//         for(int  i = 0 ;  i< n ; i++){
//             fast = fast -> next;
//         }
        
//         if(!fast) return head->next;
        
//         while(fast->next){
//              fast = fast->next;
//             slow == slow->next;
           
//         }
        
//         // ListNode * toDel = slow->next;
        
//         slow->next = slow->next->next;
        
// //         free(toDel);
        
//         return head;
        
        
        //..................
        
//             ListNode *fast = head, *slow = head;
        
//         for (int i = 0; i < n; i++) fast = fast->next;
        
//         if (!fast) return head->next;
        
//         while (fast->next) fast = fast->next, slow = slow->next;
        
//         slow->next = slow->next->next;
        
//         return head;
//     }
// };

//----------------fast, slow pointer approach----------

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

            ListNode* fast = head;

            for(int i =1; i<=n; i++){
                fast = fast->next;
            }

            if(fast == NULL) {
            return head->next;
            }

         ListNode* slow = head;
        
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
           
           ListNode* temp =  slow->next;
            slow->next = slow->next->next;
            //delete fast;
            delete temp;

      return head;

      }
    };