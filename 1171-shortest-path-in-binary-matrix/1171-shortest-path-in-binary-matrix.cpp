class Solution {
public:

int n, m;

bool isSafe(int x, int y){
    return (x>=0 && x<n && y >= 0 && y<m);
}

vector<vector<int>> directions{{1,1}, {1,0}, {0,1}, {-1, -1}, {-1,0},{0,-1}, {-1, 1}, {1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();

        if(n == 0 || m == 0 || grid[0][0] != 0){
            return -1;
        }

        queue<pair<int, int>> q;

        q.push({0,0});
        grid[0][0] = 1; //mark as visited
        
        int level = 0 ;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto it = q.front();
                q.pop();

                int x =  it.first;
                int y = it.second;

                if(x == n-1 && y ==  m-1){
                    return level+1;
                }

                for(auto& dir: directions){
                    int x_ = x+dir[0];
                    int y_ = y+dir[1];

                    if(isSafe(x_, y_) && grid[x_][y_] == 0){
                        q.push({x_, y_});
                        grid[x_][y_] =  1;
                    }
                }
            }
            level++;
        }

return -1;
    }
};