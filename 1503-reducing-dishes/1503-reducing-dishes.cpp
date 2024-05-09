typedef long long ll;

class Solution {
public:


//similar to 0-1 knapsack
//recursion + memo
// int n;
// int t[501][501];

// int solve(vector<int>& satisfaction, int i , int time){
//     if(i >= n){
//         return 0;
//     }

// if(t[i][time] != -1){
//     return t[i][time];
// }
//     int include = time*satisfaction[i] + solve(satisfaction, i+1, time+1);
//     int exclude =  solve(satisfaction, i+1, time);

//     return t[i][time] = max(include, exclude);
// }


//     int maxSatisfaction(vector<int>& satisfaction) {
//           n = satisfaction.size();
// memset(t, -1, sizeof(t));
        
//         sort(satisfaction.begin(), satisfaction.end());

//         return solve(satisfaction, 0, 1);
//     }

//-----------------------------------------------------------//

//Bottom-up (put your brain open(imp))

    int maxSatisfaction(vector<int>& satisfaction) {
       int n = satisfaction.size();

     sort( satisfaction.begin(),  satisfaction.end());

       vector<vector<ll>>dp(501, vector<ll>(501, INT_MIN));

       for(int i=0; i<501; i++){
        dp[i][0] = 0;
       }

    //    int satisfaction[i][time] = satisfaction[i];
    dp[0][1] = satisfaction[0];

       for(int i = 1; i<n; i++){
        for(int time = 1; time<=n; time++){
           ll include = satisfaction[i]*time + dp[i-1][time-1];
           ll exclude = dp[i-1][time];

           dp[i][time] = max(include, exclude);
        }
       }


ll ans = 0;
for(int time = 0; time<=n; time++){
ans = max(ans, dp[n-1][time]);
}

return ans;

    }
};