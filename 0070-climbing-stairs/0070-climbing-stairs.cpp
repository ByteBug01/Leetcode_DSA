class Solution {
public:
    
    int cs(int n, unordered_map<int, int> & memo){
        if(n==1 || n==0){
            return 1;
        }
        
        if(memo.find(n) == memo.end()){
            memo[n] = cs(n-1, memo) + cs(n-2 , memo);
        }
        return memo[n];
    }
    
    int climbStairs(int n) {
        //recursion
        //       if(n==1 || n==0){
        //           return 1;
        //       } 
        // return climbStairs(n-1) + climbStairs(n-2);
        
        //memoization
//         unordered_map<int, int> memo;
        
//         return cs(n, memo);
        
        //tabulation
//         if(n== 0 || n==1){
//             return 1;
//         }
        
//         vector<int> dp(n+1);
//         dp[0] = dp[1] = 1;
        
//         for(int i =2; i<=n ; i++){
//             dp[i] =dp[i-1] + dp[i-2];
//         }
        
//         return dp[n];
        
        
        //space optimization
        if(n== 0 || n==1){
            return 1;
        }
        
        int prev = 1, curr = 1;
        
        for(int i = 2; i<=n; i++){
            int temp = curr;
            curr= prev+curr;
            prev =temp;
            
        }
              return curr;              
    }
};