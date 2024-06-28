class Solution {
public:

int n, m;
int apples[55][55];
long long mod = 1e9 + 7;
int dp[55][55][15];

int solve(int i, int j, int k){
//base condition

if(apples[i][j] < k) return 0;

if(k == 1){
    return (apples[i][j]) >= 1 ? 1:0;
}

if(dp[i][j][k] != -1) return dp[i][j][k];


long long ans = 0;

for(int h  =i+1; h<n; h++){

    int lowerSlice = apples[h][j];
    int upperSlice = apples[i][j] - lowerSlice;

    if(upperSlice >= 1 && lowerSlice >= k  -1){
        ans = ((ans%mod) + solve(h, j, k-1)%mod)% mod;
    }
}

for(int v=j+1; v<m; v++){

    int rightSlice = apples[i][v];
    int leftSlice = apples[i][j] - rightSlice;

    if(leftSlice >= 1 && rightSlice >= k  -1){
        ans = ((ans%mod) + solve(i, v, k-1)%mod)%mod;
    }
}

return dp[i][j][k] = ans;

}
    int ways(vector<string>& pizza, int k) {
         n = pizza.size(); //row
         m = pizza[0].size(); //col

        memset(apples, 0, sizeof(apples));

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){

                apples[i][j] = apples[i][j+1];

                for(int l = i; l<n; l++){ //imp loop

                    if(pizza[l][j] == 'A') //imp
                    apples[i][j]++;

                }
            }
        }
      
      memset(dp, -1, sizeof(dp));

     return  solve(0, 0, k);

    }
};