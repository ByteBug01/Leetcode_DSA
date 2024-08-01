// class Solution {
// public:
    
//     int t[101];
    
//     int solve(vector<int>& nums, int i, int n){
//         if(i>=n) return 0;
        
//         if(t[i] != -1){
//             return t[i];
//         }
//         int steal = nums[i] + solve(nums, i + 2, n);
//         int skip = solve(nums, i+1, n);
        
//         return t[i] = max(steal,skip);
//     }
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         memset(t, -1, sizeof(t));
        
//         return solve(nums, 0, n);
//     }
// };


//space optimization------------------------

class Solution {
public:

int rob(vector<int>& nums) {

    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for(int i =1; i<n; i++){
        int pick = nums[i];

        if(i > 1)
             pick += prev2;
        

        int notpick = prev;

        int curr = max(pick, notpick);
        prev2= prev;
        prev = curr;
    }

    return prev;
 
}
};