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

 //----------giving errors---------------------------------

// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         if(head == NULL || head->next == NULL) return NULL;

//         unordered_map<int, int> freq0;

//         ListNode* temp = head;

//         while(temp->next != NULL || temp != NULL){
//             freq0[temp->val]++;
//             temp = temp->next;
//         }

// ListNode* resultList = new ListNode(NULL);

//         if(freq0[0] == 1)
//         {
//             int sum = 0;
//             ListNode* temp = head;
// //ListNode* resultList = new ListNode(NULL);

//           while(temp->next != NULL || temp != NULL)
//           {
//            sum += temp->val;
//             temp = temp->next;
//           }
//           resultList->val = sum;

//         } else{
//             ListNode* temp = head;
//           //  ListNode* resultList = new ListNode(NULL);

//           while(temp->next != NULL || temp != NULL){
//                sum += temp->val;

//                if(temp->val == 0){
//                 resultList->val = sum;
//                 resultList->next = NULL;
//                 sum = 0;
//                }

//                temp = temp->next;
//           }
               
//         }

//         return resultList;
//     }
// };

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
            if(head == NULL || head->next == NULL) return NULL;

            ListNode* temp = head->next; // firstnode = 0, skipped

            ListNode* ansList = new ListNode(0);
            ListNode* newNode = ansList;

            int sum = 0;

            while(temp != NULL){
                if(temp->val == 0){ 
                    newNode->next = new ListNode(sum); //finish the current segment and start a new node
                    newNode = newNode->next;
                    sum = 0;
                }else{
                    sum+= temp->val;
                }

                temp =  temp->next;
            }
 
 return ansList->next;

    }
};