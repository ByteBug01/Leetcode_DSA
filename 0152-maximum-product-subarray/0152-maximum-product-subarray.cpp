class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /// not with DP but in more simple thought of left , right iteration
int n  = nums.size();

        int leftprod = 1;
        int rightprod = 1;

        int ans = nums[0]; // not 0 but 1st element in case of if there is only 1 element in a vector

        for(int i = 0 ; i<n; i++){
            leftprod = leftprod == 0 ? 1: leftprod;
            rightprod = rightprod == 0 ?1 : rightprod;

             leftprod *= nums[i];
             rightprod *= nums[n - 1 - i];

             ans = max(max(leftprod, rightprod), ans);
        }

        return ans;
    }
};