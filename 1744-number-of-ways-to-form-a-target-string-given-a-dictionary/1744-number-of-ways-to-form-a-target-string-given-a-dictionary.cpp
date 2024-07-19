class Solution {
public:
//---------------memoization-----------------------------------
 int n, k;
 const int mod = 1000000007;
// int t[1001][1001];

// int solve(int i , int j,   vector<vector<long long>>& frq, string & target){
//     if( i == n) return 1;

//     if(j == k) return 0;

//     if(t[i][j] != -1) return t[i][j];

//     int not_take = solve(i, j+1, frq, target)%mod;
//     int take = (frq[target[i]-'a'][j] * solve(i+1, j+1, frq, target))% mod;

//     return t[i][j] = (take + not_take) % mod;
// }

    int numWays(vector<string>& words, string target) {
          n = target.length();
         k = words[0].length();

        vector<vector<long long>> frq(26, vector<long long>(k));

        for(int col = 0; col<k; col++){
            for(auto & word: words){
                    char ch = word[col];

                    frq[ch - 'a'][col]++; 
            }
        }

        // memset(t, -1, sizeof(t));

        // return solve(0, 0, frq, target);

        vector<vector<long long>> t(n+1, vector<long long>(k+1));

        t[0][0] = 1;

        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=k; j++){
                //not_take
                if(j<k)
                t[i][j+1] = (t[i][j+1] + t[i][j]) % mod;

                //take
                if(i<n && j<k)
                t[i+1][j+1] = (t[i+1][j+1] + t[i][j] * frq[target[i] - 'a'][j])%mod;
            }
        }

        return t[n][k];
    }
};