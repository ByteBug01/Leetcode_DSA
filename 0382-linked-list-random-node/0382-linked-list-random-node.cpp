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

 //approach -1 by rand() function
// class Solution {
// public:
// vector<int> arr;
//     Solution(ListNode* head) {
//         ListNode* temp = head;
//         while(temp != NULL){
// arr.push_back(temp->val);
// temp =  temp ->next;
//         }
//     }
    
//     int getRandom() {
//         int n = arr.size();

//         int random_idx = rand()% n;

//         return arr[random_idx];
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

//appproach - 2--------------------------Sampling Reservoir(google)----------------------------
class Solution {
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        ListNode* curr = temp;
        int size = 1;
        while(curr) {
            //choosing probability is 1/size (reservior sampling)
            if(rand()%size == 0)
                res = curr->val;
            curr = curr->next;
            size++;
        }
        return res;
    }
};