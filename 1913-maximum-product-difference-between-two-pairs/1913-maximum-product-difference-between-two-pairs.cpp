class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int a = nums[0]*nums[1];
        int b = nums[n-1]*nums[n-2];
        
        int pro = b-a;
        
        return pro;
    }
};