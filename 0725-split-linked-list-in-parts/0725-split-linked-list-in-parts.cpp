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

    std::vector<ListNode*> result(k, nullptr);
    int n = 0;
    ListNode* temp = head;

    // Calculate the total length of the linked list
    while (temp) {
        n++;
        temp = temp->next;
    }

    int partSize = n / k;        // Minimum size of each part
    int extra = n % k;           // Parts that will have one extra node

    ListNode* curr= head;
    for (int i = 0; i < k && curr; ++i) {
        result[i] = curr;
        int currentPartSize = partSize + (extra > 0 ? 1 : 0);
        extra--;

        // Move to the end of the current part
        for (int j = 1; j < currentPartSize; ++j) {
            curr = curr->next;
        }

        // Split the list
        ListNode* nextPart = curr->next;
        curr->next = nullptr;
        curr = nextPart;
    }

    return result;
     


    }
};