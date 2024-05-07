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

 ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        //***bkwas**//
    //      ListNode *temp = head;
    //     int length = 0;
    
    //     while (temp != NULL) {
    //         temp = temp->next;
    //         length++;
    //     }

    //   stack<ListNode*> st;
    //     temp = head;
    //     while (temp != NULL) {
    //         st.push(temp);
    //         temp = temp->next;
    //     }

//tc failed............//
// if(head == NULL) return head;
//        head = reverseList(head); //to reverse the linkedList

// ListNode* curr = head;
// int carry = 0;

// while(curr != NULL){
//     int newval = 2* curr->val + carry;

//     curr->val = newval % 10;
//     carry = newval / 10;

//     if( carry  && !curr->next){  //if carry remains for the leftmost digit
//         curr->next = new ListNode(carry);
//         carry = 0;
//     }


//     curr = curr->next;

// }

// return reverseList(head);

head = reverseList(head);

ListNode* curr = head;
ListNode* prev = NULL;

int carry = 0;

while(curr != NULL ){
    int newval  = 2 * curr->val + carry;
    curr->val = newval % 10;

    if(newval >= 10){
        carry = 1;
    }else{
        carry = 0;
    }

    prev = curr;
    curr = curr->next;
}

if(carry != 0){
    ListNode* h = new ListNode(carry);
    prev->next = h;
}

return reverseList(head);

//don' be lazy
    }
};