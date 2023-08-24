class Solution {
public:
    
//     int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         int  m =matrix[0].size();
//         if(j<0 || j>m-1) return 1e9;
//         if(i==0) return matrix[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int st = matrix[i][j] + solve(i-1,j,matrix,dp);
//         int ld = matrix[i][j] + solve(i-1,j+1,matrix,dp);
//         int rd = matrix[i][j] + solve(i-1,j-1,matrix,dp);
        
//         return dp[i][j] = min(st,min(ld,rd));
//     }
    int minFallingPathSum(vector<vector<int>>& A) {
      int m = A.size();

        vector<vector<int>>dp(m, vector<int>(m, 0));
        
        for (int i = 0; i < m; i++)
            dp[0][i] = A[0][i];
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0)
                    dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                else if (j == m-1)
                    dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                else
                    dp[i][j] = A[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
            }
        }
        
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[m-1][j]);
        }
        
        return ans;
    }
};