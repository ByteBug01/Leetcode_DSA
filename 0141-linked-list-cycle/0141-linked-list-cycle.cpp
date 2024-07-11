/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head  == NULL || head -> next == NULL)
             return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast -> next && fast -> next-> next){
            fast = fast -> next -> next;
            slow = slow ->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
*/

//------using unordered_set------------------------------------------
// class Solution {
// public:

// //while trversing if any node is seen which is already pesent in map then return false
//     bool hasCycle(ListNode *head) {

// if(head == NULL || head->next == NULL){
//     return false;
// }

//         // unordered_map<int, int> mp;

//         unordered_set<ListNode*> mp;

//         ListNode* temp  = head;

//         while(temp!= NULL &&  temp->next != NULL){
//             if(mp.find(temp) == mp.end()){
//                mp.insert(temp);
//             }
//             else{
//                 return true;
//             }

//             temp = temp->next;
//         }

//         return false;
//     }
// };


//-----------------using unordered_map----------------------------------------
// class Solution {
// public:

// //while trversing if any node is seen which is already pesent in map then return false
//     bool hasCycle(ListNode *head) {
//          unordered_map<ListNode*, int> mp;

//              ListNode* temp  = head;

//         while(temp!= NULL &&  temp->next != NULL){

//             if(mp.find(temp) != mp.end()){
//                 return true;
//             }

//             mp[temp] = 1;

//             temp =  temp->next;
//         }

//         return false;
//     }
// };

//------------------------------------------
//-------------in constant space -------------------
// with slow and fast pointer method, at some point slow and fast pointer meet that means there is cycle

class Solution {
public:

    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next; //2 step
            slow = slow->next; // 1 step


            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};