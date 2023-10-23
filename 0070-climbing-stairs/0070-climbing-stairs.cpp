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
        unordered_map<int, int> memo;
        
        return cs(n, memo);
                            
    }
};