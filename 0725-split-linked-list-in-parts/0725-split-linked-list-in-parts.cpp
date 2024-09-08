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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
    //    int n = 0;
    //    ListNode* tmp = head;

    //   while(tmp != NULL){
    //      tmp = tmp->next;
    //      n++;
    //   }
    
    // vector<ListNode*> ans;
    // int  partionsize = 0;
    // if(k > n){
    //      partionsize = k/n;
    // }
     
   
    
    // for(int i = 0; i<k; i++){
    //     vector<ListNode*> tmp;
    //     while(n--){
    //         //ListNode* temp = head;
    //         tmp.push_back(temp);
    //         temp->next;
    //     }
    //     ans.push_back(tmp);
    // }

        int n = 0;
       ListNode* tmp = head;

      while(tmp != NULL){
         tmp = tmp->next;
         n++;
      }

vector<ListNode*> ans(k, NULL);

if(head == NULL) return ans;

int bucketNodes = n/k;
int extraNode = n%k;

ListNode* curr =  head;
ListNode* prev = NULL;

for(int i=0; i<k; i++){
    ans[i] = curr;

    for(int j = 0; j<(n/k) + (extraNode>0)?1:0; j++){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    extraNode--;
}
    
return ans;

    }
};