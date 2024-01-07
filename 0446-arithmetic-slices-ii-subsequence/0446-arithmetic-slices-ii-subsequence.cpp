class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int totalCount = 0;

     
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];

              
                if (diff < INT_MIN || diff > INT_MAX)
                    continue;

                int count = dp[j].count(diff) ? dp[j][diff] : 0;

                
                totalCount += count;
                dp[i][diff] += count + 1;
            }
        }

        return totalCount;
    }
};