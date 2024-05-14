class Solution {
public:

//backtracking---------------------------------
int n, m;
int dfs(vector<vector<int>>& grid, int i , int j){
    
    if(i >= m || i< 0 || j>= n || j<0 || grid[i][j] == 0){
        return 0;
    }

    int temp = grid[i][j];
    grid[i][j] = 0;

    int up = dfs(grid, i-1, j);
    int down = dfs(grid, i+1, j);
    int left  = dfs(grid, i, j-1);
    int right = dfs(grid, i, j+1);

    grid[i][j] = temp;

    return temp+ max(max(max(up, down), left), right);
}


    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
int maxsum =0;
for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
        int sum = dfs(grid, i, j);
        maxsum = max(sum, maxsum);
    }
}
        return maxsum;
    }
};