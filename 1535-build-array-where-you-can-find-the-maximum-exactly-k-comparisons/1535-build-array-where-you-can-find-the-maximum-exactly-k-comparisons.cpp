class Solution {
public:
int N,M,K;
int MOD = 1e9 + 7;
int t[51][51][101];

int solve(int idx, int searchCost, int max_so_far){
    if(idx == N){
        if(searchCost == K){
            return 1;
        }
        return 0;
    }

    if(t[idx][searchCost][max_so_far] != -1){
        return t[idx][searchCost][max_so_far];
    }
    int ans = 0;
    //har index k pas 1 to m tk ki value ki possiblity hai
    for(int i = 1; i<= M; i++){
            
        if(i > max_so_far){ //agr koi max_so_far se bda number milta hai toh searchCost increase hoga +1 se
            ans = (ans + solve(idx+1, searchCost+1, i)) % MOD;
        }
         else{
            ans =  (ans+ solve(idx+1, searchCost, max_so_far)) % MOD;
         }

    }
    return t[idx][searchCost][max_so_far] = ans % MOD;
}
    
    int numOfArrays(int n, int m, int k) 
    {
        memset(t, -1, sizeof(t));
        N=n;
        M=m;
        K=k;
        return solve(0, 0, 0);
    }
};