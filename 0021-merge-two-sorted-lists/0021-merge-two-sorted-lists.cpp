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
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL){
//             return list2;
//         }
//         if(list2 == NULL){
//             return list1;
//         }
//         ListNode *ptr1 = list1;
//         ListNode *ptr2 = list2;
//         ListNode *newNode = new ListNode();
//         ListNode *ptr3 = newNode;

//         while(ptr1 != NULL and ptr2 != NULL){
//             if(ptr1->val < ptr2->val){
//                 ptr3 ->next = ptr1;
//                 ptr1= ptr1->next;
//             }
//         else{
//                 ptr3 ->next = ptr2;
//                 ptr2= ptr2->next;
//             }
//            ptr3=ptr3->next;
//         }
// while(ptr1 != NULL){
//     ptr3->next = ptr1;
//     ptr1 = ptr1->next;
//     ptr3= ptr3->next;
// }
// while(ptr2 != NULL){
//     ptr3->next = ptr2;
//     ptr2 = ptr2->next;
//     ptr3= ptr3->next;
// }
//    return newNode; }
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;

        if(list2 == NULL) return list1;

        ListNode* result;

        if(list1->val < list2->val){
             result = list1;
             result->next = mergeTwoLists(list1->next, list2);
        }else{
            result = list2;
             result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};