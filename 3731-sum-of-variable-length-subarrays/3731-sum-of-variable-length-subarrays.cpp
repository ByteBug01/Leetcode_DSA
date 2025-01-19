class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int strt = max(0, i-nums[i]);

            int tmp =0;
            for(int j = strt; j<=i; j++){
                tmp += nums[j];
            }
            ans+= tmp;
        }

        return ans;
    }
};