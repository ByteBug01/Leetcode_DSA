class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //optimised....................//
        
//         unordered_map<int, int> mp;
//         int sum =0;
//          int count = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             sum+=nums[i];
            
//             if(sum == goal)
//                 count ++;
            
//             if(mp.find(sum-goal) != mp.end())
//                 count+= mp[sum - goal];
            
//             if(mp.find(sum) != mp.end())
//                 mp[sum]++;
//             else
//                 mp[sum] = 1;
//         }
//         return count;
        
        //,..........................//
        // bruteforce..................//
        
//         int n = nums.size();
//         int cnt = 0;
//          for (int start = 0; start < n; start++) {
//         for (int end = start; end < n; end++) {
    
//             int sum = 0;
//             for (int i = start; i <= end; i++) {
//                 sum += nums[i];
//             }
//            if(sum == goal){
//                cnt++;
//            }
//         }}
//         return cnt;
        
        //..................//
        
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        int cnt = 0;
        int currSum =  0;
        
        mp[0] = 1;
        
        for(int  i = 0; i<n; i++){
            
            currSum += nums[i];
            
            int remainingSum =  currSum -  goal;
            
            if(mp.find(remainingSum) != mp.end()){
                cnt += mp[remainingSum];
            }
            
            mp[currSum]++;
        }
       
        return cnt;
    }
};