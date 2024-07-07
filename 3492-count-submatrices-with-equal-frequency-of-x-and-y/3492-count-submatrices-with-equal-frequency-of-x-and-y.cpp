class Solution {
public:

    vector<vector<int>> solve_prefix(char ch, vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> result(r, vector<int>(c, 0));
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result[i][j] = (grid[i][j] == ch) ? 1 : 0;
            }
        }

        // Prefix evaluate row-wise
        for (int i = 0; i < r; i++) {
            for (int j = 1; j < c; j++) {
                result[i][j] += result[i][j - 1];
            }
        }

        // Prefix evaluate column-wise
        for (int j = 0; j < c; j++) {
            for (int i = 1; i < r; i++) {
                result[i][j] += result[i - 1][j];
            }
        }

        return result;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> grid_x = solve_prefix('X', grid);
        vector<vector<int>> grid_y = solve_prefix('Y', grid);

        int ans = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid_x[r][c] == grid_y[r][c] && grid_x[r][c] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};