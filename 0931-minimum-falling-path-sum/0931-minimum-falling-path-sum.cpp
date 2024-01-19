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
    
    
    
    //....................
    
//     int minFallingPathSum(vector<vector<int>>& A) {
//       int m = A.size();

//         vector<vector<int>>dp(m, vector<int>(m, 0));
        
//         for (int i = 0; i < m; i++)
//             dp[0][i] = A[0][i];
        
//         for (int i = 1; i < m; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (j == 0)
//                     dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
//                 else if (j == m-1)
//                     dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
//                 else
//                     dp[i][j] = A[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
//             }
//         }
        
//         int ans = INT_MAX;
//         for (int j = 0; j < m; j++) {
//             ans = min(ans, dp[m-1][j]);
//         }
        
//         return ans;
//     }
    
    //............
//     int n ; 
//     int t[101][101];
    
//     int solve(vector<vector<int>> &A, int row, int col, vector<vector<int>>& t){
        
//         if(row == n-1){
//             return A[row][col];
//         }
        
//         //..............
//         if(t[row][col] != -1){
//             return t[row][col];
//         }
//         //...............
        
//         int sum = A[row][col];
        
//         int minSum = INT_MAX;
        
//         if(row+1 < n && col>= 0)
//        minSum = min(minSum, sum+solve(A, row+1, col-1,t )) ;
      
//         if(row+1<n)
//         minSum = min(minSum, sum+solve(A, row+1, col,t)) ;
       
//         if(row+1< n && col+1 <n)
//         minSum = min(minSum, sum+ solve(A, row+1, col+1, t));
        
//         return t[row][col] = minSum;
//     }
    
    
//      int minFallingPathSum(vector<vector<int>>& A) {
     
//          n = A.size();
//           memset(t, -1, sizeof(t));
         
//          int row = 0;
         
//          int ans = INT_MAX;
     
//      for(int col = 0; col<n; col++){
//          ans = min(ans, solve(A, row, col, t));
//      }
     
     
//      return ans;
//      }
    //...........
//      int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
//         if(row == A.size()-1)
//             return A[row][col];
//         if(t[row][col] != -1)
//             return t[row][col];
        
//         int minSum = INT_MAX;
        
//         for(int shift = -1; shift<=1; shift++) {
//             if(col + shift >=0 && col+shift < A[row].size()) {
//                 minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
//             }
//         }
        
//         return t[row][col] = minSum;
//     }
//     int minFallingPathSum(vector<vector<int>>& A) {
//         int m = A.size(); //row
//         int n = m; //column
//         vector<vector<int>> t(101, vector<int>(101));
//         for(int i = 0; i<101; i++) {
//             for(int j = 0; j<101; j++) {
//                 t[i][j] = -1;
//             }
//         }
//         int result = INT_MAX;
//         for(int col = 0; col<n; col++) {
//             result = min(result, MFS(A, 0, col, t));
//         }
//         return result;
//     }
    
     int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> prev(n);
        for(int col = 0; col<n; col++)
            prev[col] = A[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = A[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};