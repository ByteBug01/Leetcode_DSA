class neighborSum {
public:

   vector<vector<int>> grid;
   unordered_map<int, pair<int, int>> position;
    int n;

vector<pair<int, int>> adjacent =  {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> diagonal = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    neighborSum(vector<vector<int>>& grid): grid(grid) {
     n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                position[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {

        int sum = 0;
        auto [x, y] = position[value];
        // int x = pos.first;
        // int y = pos.second;
        
        for (auto& it: adjacent) {
            int x_ = x + it.first;
            int y_ = y + it.second;
            if (x_ >= 0 && x_< n && y_ >= 0 && y_ < n) {
                sum += grid[x_][y_];
            }
        }
    return sum;
    }
    
    int diagonalSum(int value) {
         int sum = 0;
        auto pos = position[value];
        int x = pos.first;
        int y = pos.second;
        
        for (auto& it: diagonal) {
            int x_ = x + it.first;
            int y_ = y + it.second;
            if (x_ >= 0 && x_< n && y_ >= 0 && y_ < n) {
                sum += grid[x_][y_];
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */