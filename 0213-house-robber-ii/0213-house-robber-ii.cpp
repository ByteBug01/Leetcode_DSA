class Solution {
public:
    
    //memoization + recursion
    //solve function from hoouse robber-
//     int t[101];
    
//     int solve(vector<int> &nums, int i, int n){
//         if(i>n)
//             return 0;
        
//         if(t[i] != -1)
//             return t[i];
        
//         int take = nums[i]  + solve(nums, i+2, n); //steals ith house and then skips next house move to i+2th house
//         int skip =  solve(nums, i+1, n);
        
//         return t[i] = max(take, skip);
//     }
    
    
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         if(n == 1)
//             return nums[0];
        
//         if(n == 2)
//             return max(nums[0], nums[1]);
        
//         memset(t, -1, sizeof(t));
        
//         int take_0th_house = solve(nums, 0, n-2);
        
        
//         memset(t, -1, sizeof(t));
        
//         int take_1st_house = solve(nums, 1, n-1);
        
//         return max(take_0th_house, take_1st_house);
//     }
    
    
    //bottom-up.....tabulation
    
     int rob(vector<int>& nums) {
         
         int n = nums.size();
         
         if(n == 1){
             return nums[0];
         }
         
         vector<int> t(n+1, 0);
         
         t[0] =  0; // t[i] = money stolen when you have  i houses
         
         // case - 1...(take thte 1st house, henx=ce skip the last house so hum loop n-1 tk chlaenge)
         
         for(int i = 1; i<= n-1; i++){
             int skip = t[i-1];
             
             int take = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0);
             
             t[i] = max(take, skip);
         }
         
         int ans1 = t[n-1];
         
         t.clear(); // imp.
         
         //case - 2...(skip 1st hosue - hence you can take the last house..hum loop 2 se n tk chlaenge)
         t[0] = 0;  //imp.
         t[1] = 0;  // imp.
         
         for(int i = 2; i<=n; i++){
             int skip = t[i-1];
             
             int take = nums[i-1] + ((i-2 >= 0) ? t[i-2]  : 0);
             
             t[i] = max(skip, take);
         }
         
         int ans2 = t[n];
         
         
         return max(ans1, ans2);
     }
};