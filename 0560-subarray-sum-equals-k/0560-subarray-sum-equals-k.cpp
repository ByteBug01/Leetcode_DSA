class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =  nums.size();
        
        unordered_map<int, int> mp ;
        
        int cumsum =  0 ;
        int ans = 0;
        
        mp.insert({0, 1}); //for corner case, if all elements of nums = k
        
        for(int  i = 0 ; i<n; i++){
            cumsum += nums[i];
            
            if(mp.find(cumsum-  k) != mp.end()){
                ans += mp[cumsum - k];
            }
            
            mp[cumsum]++;
        }
        
        return ans;
    }
};