class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n  =  nums.size();

        if(n <= 4) return 0;
        
        sort(nums.begin(), nums.end());

        int a = nums[n-1] - nums[3]; //removed first 3 smallest ele
        
        int b = nums[n-2] - nums[2]; //removed first 2 smallest, last largest

        int c = nums[n-3] - nums[1]; //removed smallest and last 2 largest

        int d = nums[n-4] - nums[0]; // removed last 3 largest

        return min({a, b, c, d});
    }
};