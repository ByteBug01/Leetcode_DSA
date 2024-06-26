// class Solution {
// public:
    
//     int n;
//     int t[2501][2501]; //for memoization
    
//      int lis(vector<int>& nums, int prev_idx, int curr_idx) {
//        if(curr_idx == n)
//            return 0;
        
//         if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
//             return t[prev_idx][curr_idx];
        
//         int taken = 0;
         
//         if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
//             taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
//         int not_taken = lis(nums, prev_idx, curr_idx+1);
        
//         if(prev_idx != -1)
//             t[prev_idx][curr_idx] =  max(taken, not_taken);
        
//         return max(taken, not_taken);
            
//     }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     memset(t, -1, sizeof(t)); //shortcut to initialise to -1
    //     n = nums.size();
    //     return lis(nums, -1, 0);
    // }
    //.......................
//     int n ;
//     int t[2501][2501];
    
//     int solve(vector<int> &nums, int i , int P){
//        if(i>= n) return 0;
        
//         if(P != -1 && t[i][P] != -1){
//             return t[i][P];
//         }
        
//         int take = 0 ;
//         if(P == -1 || nums[i] > nums[P]){
//             take = 1 + solve(nums, i+1, i);  // length return krna hai
//         }
        
//        int skip = solve(nums, i+1 , P);
        
//         if(P != - 1)
//             t[i][P] = max(take, skip);
        
        
//         return max(take, skip);
        
        
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
       
//         n = nums.size();
        
//         memset(t, -1, sizeof(t));
        
//         return solve(nums, 0, -1);
//     }
    
    // BOTTOM UP ----VERY EASY------------------------------------
//     int lengthOfLIS(vector<int>& nums) {
    
//     int n = nums.size();

//     vector<int> t(n, 1);

//     int maxLen = 1; //as each element is itself a subsequence 

//     for(int i =0; i<n; i++){
//         for(int j = 0; j<i; j++){
//             if(nums[j] < nums[i]){
//                 t[i] = max(t[i], t[j] + 1); //t[j] ke val me 1 add hoga, kyuki t[i] ki initial val 1 hai
//                 maxLen = max(maxLen, t[i]);
//             }
            
//         }
//     }
// return maxLen;
// }
// };

//PATIENCE SORTING----------------------------------

class Solution {
public:
 int lengthOfLIS(vector<int>& nums) {
        int n  =nums.size();

        vector<int> sorted;

        for(int i  =0; i<n; i++){
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]); //just greater than or equal to nums[i]

            if(it == end(sorted)){  //no lele found which is greater than or equal to nums[i]
              sorted.push_back(nums[i]); //mtlb yhi greatest hai
            }else{
                *it = nums[i]; //agr mila toh replace krdo
            }
        }

        return sorted.size();
 }
};
   