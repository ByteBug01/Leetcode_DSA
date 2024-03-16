class Solution {
public:
    
    //revisit this problem ...similar to leetcode 560, 1074, 930
    int findMaxLength(vector<int>& nums) {
        
        int n =  nums.size();
       
        unordered_map<int, int> mp;
        
        int cursum =  0;
        mp[0] = -1;
        
        int ans =  0;
        
        for(int i = 0 ;  i<n; i++ ){
            cursum += (nums[i] == 1) ?1: -1;
            
            if(mp.find(cursum) != mp.end()){
                ans = max(ans, i-mp[cursum]);
            }else{
                mp[cursum] = i;
            }
        }
        
        return ans;
    }
};