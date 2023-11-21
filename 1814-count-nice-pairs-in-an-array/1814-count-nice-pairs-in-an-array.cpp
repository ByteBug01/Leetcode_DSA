class Solution {
public:
    
     int reverse(int num) 
    {
        int rev = 0;
        while (num > 0) 
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
         const int mod = 1000000007;
        int len = nums.size();
        unordered_map<int,int> mapp ;
        int ans = 0 ;
    
        for (int i = 0; i < len; ++i)
        {    
            int x = nums[i] - reverse(nums[i]) ;
            mapp[x]++ ;
        }
        for(auto x : mapp)
        {
            int count = x.second ;
            ans = (ans % mod + ((long)count*(long)(count-1)/2) % mod) % mod ;
        }

        return ans ;
    }
};