// class Solution {
// public:
   
//     bool canPartition(vector<int>& arr) {
//        int n = arr.size();
//          int totSum=0;
    
//     for(int i=0; i<n;i++){
//         totSum+= arr[i];
//     }
    
//     if (totSum%2==1) return false;
    
//     else{
//         int k = totSum/2;
//         vector<bool> prev(k+1,false);
    
//         prev[0] = true;
        
//         if(arr[0]<=k)
//             prev[arr[0]] = true;
        
//         for(int ind = 1; ind<n; ind++){
//             vector<bool> cur(k+1,false);
//             cur[0] = true;
//             for(int target= 1; target<=k; target++){
//                 bool notTaken = prev[target];
        
//                 bool taken = false;
//                     if(arr[ind]<=target)
//                         taken = prev[target-arr[ind]];
            
//                 cur[target]= notTaken||taken;
//             }
//             prev = cur;
//         }
        
//         return prev[k];
//     }
//     }
// };

class Solution {
public:
   
   //reference from "subsetsum (gfg)"

   bool solve(vector<int>& nums, int idx, int k, vector<vector<int>>& dp){
    if(k == 0) return true;

    if(idx == 0) return nums[idx]==k;

    if(dp[idx][k] != -1){
        return dp[idx][k] ;
    }

    bool not_take = solve(nums, idx -1, k, dp );

    bool take  = false;
if(nums[idx] <= k) take = solve(nums, idx-1, k-nums[idx], dp);

return dp[idx][k] = take | not_take;
   }



    bool canPartition(vector<int>& nums) {

        
        int n = nums.size();

        int totsum = 0;

       // vector<vector<int>> dp(n+1, vector<int>((totsum/2)+1, -1));

        for(int i = 0; i<n; i++){
            totsum += nums[i];
        }

        if(totsum % 2 != 0){
            return false;
        }

        int k = totsum / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        
        return solve(nums, n - 1, k, dp);
    }
};