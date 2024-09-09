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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        //kind of splitting LL

        vector<vector<int>> mat(m, vector<int>(n, -1));

      int k = 0;
      int top = 0, down = m-1;
      int left = 0, right = n-1;

      while(top<= down && left <= right){
        if(k == 0){
            //left to  right
            for(int i = left; head != NULL&&i<=right; i++){
                mat[top][i] = head->val;
                head = head->next;
            }
            top++;
        }

         if(k == 1){
            //top to down
            for(int i = top; head != NULL && i<=down; i++){
                mat[i][right] = head->val;
                head = head->next;
            }
            right--;
        }

         if(k == 2){
            //right to left
            for(int i = right; head != NULL && i>=left; i--){
                mat[down][i] = head->val;
                head = head->next;
            }
            down--;
        }

         if(k == 3){
            //down to top
            for(int i = down; head != NULL && i>=top; i--){
                mat[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

     k = (k+1)%4; //will be between 0,1,2,3
      }
 
 return mat;
    }
};