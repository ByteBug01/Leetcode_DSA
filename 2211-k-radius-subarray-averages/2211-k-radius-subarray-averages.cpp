class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0) return nums;

        vector<int> ans(n, -1);

        if(n < 2*k+1) return ans;

        vector<long long> prefixsum(n, 0);

        prefixsum[0] = nums[0];

        for(int i  =1; i<n; i++){
           prefixsum[i] = prefixsum[i-1] + nums[i]; //remember
        }

long long sum = 0;
        for(int i = k; i<=n-k-1; i++){
           int left_idx = i - k;
           int right_idx = i + k;

           sum = prefixsum[right_idx];

           if(left_idx > 0){
                 sum -= prefixsum[left_idx - 1]; //remember
           }
           ans[i] = sum/(2*k + 1);

        }

return ans;
    }
};