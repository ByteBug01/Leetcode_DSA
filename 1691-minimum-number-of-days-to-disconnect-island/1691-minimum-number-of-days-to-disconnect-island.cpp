class Solution {
public:

int n, m;

void dfs(int i, int j , vector<vector<int>>& grid, vector<vector<int>>& vis ){
    if(i >= m || i < 0 || j >= n || j < 0 || vis[i][j] || grid[i][j] == 0){
        return;
    }

    vis[i][j] = 1;

    dfs(i, j-1, grid, vis);
    dfs(i-1, j, grid, vis);
    dfs(i, j+1, grid, vis);
    dfs(i+1, j, grid, vis);

}

int cntIslands(vector<vector<int>>& grid){

    vector<vector<int>> vis(m, vector<int>(n, 0));
    int cnt = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                dfs(i, j, grid, vis);
                cnt++;
            }
        }
    }

    return cnt;
}

int minDays(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int islandCnt = cntIslands(grid);

    if(islandCnt == 0 || islandCnt > 1) return 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                grid[i][j] = 0;

                if(cntIslands(grid) > 1 || cntIslands(grid) == 0){
                    return 1;
                }

                grid[i][j] = 1;
            }
        }
    }

    return 2;
}
};
