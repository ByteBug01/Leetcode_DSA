class Solution {
public:
    //dp
//    int M;
//     int N;
//     int MOD = 1e9+7;
//     vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     int t[51][51][51];
//     int solve(int maxMove, int startRow, int startColumn) {
//         if(startRow < 0 || startRow >= M || startColumn < 0 || startColumn >= N) {
//             return 1; //Found one path out
//         }

//         if(maxMove <= 0) 
//             return 0;

//         if(t[maxMove][startRow][startColumn] != -1) {
//             return t[maxMove][startRow][startColumn];
//         }

//         int result = 0;
//         for(auto &dir : directions) {
//             int x = startRow    + dir[0];
//             int y = startColumn + dir[1];
            
//             result = (result + solve(maxMove-1, x, y)) % MOD;
//         }

//         return t[maxMove][startRow][startColumn] = result%MOD;

//     }
    
    
     int M=1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(int n, int m, int maxMove, int startRow, int startColumn){
        if(startColumn<0 || startColumn>=n || startRow<0 || startRow>=m) return 1;
        if(maxMove == 0) return 0;
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];

        int up = solve(n, m, maxMove-1, startRow-1, startColumn);
        int down = solve(n, m, maxMove-1, startRow+1, startColumn);
        int left = solve(n, m, maxMove-1, startRow, startColumn-1);
        int right = solve(n, m, maxMove-1, startRow, startColumn+1);

        return dp[startRow][startColumn][maxMove] = ((up+down)%M + (left+right)%M)%M;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//          memset(t, -1, sizeof(t));
//         int M = m;
//         int N = n;
       
//         return solve(startRow, startColumn, maxMove);
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(n, m, maxMove, startRow, startColumn);

    }
};