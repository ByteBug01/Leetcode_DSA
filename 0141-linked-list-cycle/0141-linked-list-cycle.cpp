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

//------using hashmap, and marking visited---------------------
class Solution {
public:

//while trversing if any node is seen which is already pesent in map then return false
    bool hasCycle(ListNode *head) {

if(head == NULL || head->next == NULL){
    return false;
}

        // unordered_map<int, int> mp;

        unordered_set<ListNode*> mp;

        ListNode* temp  = head;

        while(temp!= NULL &&  temp->next != NULL){
            if(mp.find(temp) == mp.end()){
               mp.insert(temp);
            }
            else{
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
};