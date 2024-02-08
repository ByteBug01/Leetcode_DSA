class Solution {
public:
    
    int t[10001];
    int helper( int  n){
        
        if(n ==  0){
            return 0;
        }
        
         
        if(t[n] != -1){
            return t[n];
        }
        
        int  mincnt = INT_MAX;
        
       
        for(int i = 1; i*i <= n; i++){
           int ans = 1 + helper(n-i*i);
        
            mincnt = min(mincnt, ans);
        }
        
        return t[n]= mincnt; 
        
    }
    
    int numSquares(int n) {
        memset(t, -1, sizeof(t));
   return  helper(n);
    }
};