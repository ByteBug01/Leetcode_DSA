class Solution {
public:
 int m, n;

 //dfs- recursive
    int findArea(vector<vector<int>>& grid, int row, int col, vector<vector<bool>> &seen){
        if(row >= m || row < 0 || col >= n || col < 0 || seen[row][col] || grid[row][col] == 0) return 0;

        seen[row][col] = true;

        return (1 + findArea(grid, row, col+1, seen) + findArea(grid, row+1, col, seen) +
                    findArea(grid, row, col-1, seen) + findArea(grid, row-1, col, seen));
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
         m = grid.size();
         n =  grid[0].size();

         vector<vector<bool>> seen(m, vector<bool>(n, false));

        int ans = 0;
        for(int i  =0; i<m ; i++){
            for(int j =0; j<n; j++){
                ans = max(ans, findArea(grid, i, j, seen));
            }
        }


        return ans;
    }
};