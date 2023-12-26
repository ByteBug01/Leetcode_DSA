class Solution {
public:
    //two values are changing that are n and target
    //t[n][target]
    
    int t[31][1001];
    int MOD = 1e9 + 7;
    
    int solve(int n, int k, int target){
        
        if(target<0){ //wrong path
            return 0;
        }
        
        
        if(t[n][target] != -1){
            return t[n][target];
        }
        if(n == 0){
            return target == 0; //return true (i,e = 1)
        }
        
        
        int ways = 0;
        for(int face = 1; face<= k; face++){ //one dice rolled
            ways = (ways + solve(n-1, k, target-face))%MOD;
        }
        
        return  t[n][target] = ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        //dp
        memset(t, -1, sizeof(t));
        return solve(n, k, target);
    }
};