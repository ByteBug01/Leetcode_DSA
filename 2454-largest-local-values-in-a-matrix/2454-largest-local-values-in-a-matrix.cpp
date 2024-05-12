class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
    vector<vector<int>> ans_grid;

    for (int i = 1; i < n - 1; ++i) {
        vector<int> row;
        for (int j = 1; j < n - 1; ++j) { // until j=1 we are evaluating for 1st row of new_grid
            vector<int> submatrix = {
                grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                grid[i][j - 1], grid[i][j], grid[i][j + 1],
                grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]
            };
            row.push_back(*max_element(submatrix.begin(), submatrix.end()));
        }
        ans_grid.push_back(row);
    }

    return ans_grid;
    }
};