// class Solution {
// public:

//top-down - memoization=------------------------------------------

//     int m, n;

//     int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
//         if(i>= m || j >= n ) return 0;

//         if(matrix[i][j] == 0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         int right = solve(matrix, i, j+1, dp);
//         int diagonal = solve(matrix, i+1, j+1, dp);
//         int down = solve(matrix, i+1, j, dp);

//         return dp[i][j] = 1 + min(right, min(diagonal, down));
//     }

//     int countSquares(vector<vector<int>>& matrix) {
//          m = matrix.size();
//          n = matrix[0].size();

//         int ans  = 0;

//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         for(int i=0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 if(matrix[i][j] == 1){
//                    ans += solve(matrix, i, j, dp);
//                 }
//             }
//         }


//         return ans;
//     }
// };

//bottom-up--------------------------------------------------

class Solution {
public:

 int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = 0 ;

    vector<vector<int>> t(m, vector<int>(n, 0));

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            
            if(i == 0 || j == 0) {
                t[i][j] = matrix[i][j];
            }else if(matrix[i][j] == 1){
                t[i][j] = 1  + min({t[i-1][j] , t[i-1][j-1], t[i][j-1]});
            }

             ans += t[i][j];
        }
    }

    return ans;

 }
};