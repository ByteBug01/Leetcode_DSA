/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// class Solution {
// public:

// // Bruteforce------------------------------
//     ListNode *detectCycle(ListNode *head) {
//         unordered_map<ListNode* , int> mp;
        
//         ListNode* temp = head;

//         while(temp != NULL){

//             if(mp[temp] != 0){ // check if temp has been encountered again
//                 return temp; //  A loop is detected hence return temp
//             }

//             mp[temp] = 1; 
//             temp = temp->next;
//         }

//         return NULL;
//     }
// };


//-------------optimal (with slow , fast pointer)--------------------
class Solution {
public:

  ListNode *detectCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != NULL && fast->next != NULL){
          slow = slow->next;
          fast = fast->next->next;

          if(fast == slow){ //cycle detected
                  slow = head; //  // Reset the slow point to the head 

                  while(slow != fast){  // When slow and fast meet again it's the first node of the loop

                    slow = slow->next;
                    fast = fast->next;
                  }

                   return slow;
          }
      }

return NULL;
     
  }
};