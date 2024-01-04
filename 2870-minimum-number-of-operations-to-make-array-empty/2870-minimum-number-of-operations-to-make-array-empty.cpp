class Solution {
public:
    
    int minOperations(vector<int>& nums) {
//         int n = nums.size();
        
//         unordered_map<int , int> um;
//         for(auto it: nums){
//             um[it]++;
//         }
        
//         int cnt3=0, cnt2=0;
        
//         for(auto it: um){
//             if(it.second%3 != 0 && it.second% 2 != 0){
//                 return -1;
//             }
//             else{
//             if(it.second % 3) {
//                 int c  = it.second/3;
//                 cnt3+=c;
//             }
                
//             else if(it.second%2) {
//                 int c  = it.second/2;
//                 cnt2+=c;
//             }
//             }
            
//         }
//         int op1 = cnt3+cnt2;
        
//         return op1;
        
        
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(auto &it: nums){
            mp[it]++;
        }
        
        for(auto &it: mp){
            
            int f = it.second;
            
            if(f == 1){
                return -1;
            }
                ans += ceil((double) f / 3);
            
        }
        
        return ans;
    }
};