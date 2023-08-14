class Solution {
public:
    int miniPath(int i, int j, vector<vector<int>> & triangle, int n, vector<vector<int>> & dp){
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==n-1) return triangle[i][j];
        
        int down = triangle[i][j]+miniPath(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+miniPath(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return miniPath(0,0,triangle,n, dp);
    }
};