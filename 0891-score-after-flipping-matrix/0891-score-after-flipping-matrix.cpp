class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int  m = grid.size();
        int n  = grid[0].size(); 

            // toggle for 1st value of a row, it should be 1
        for(int i = 0; i<m; i++){
              if(grid[i][0] == 0){
             
              for(int j = 0; j<n; j++){
                grid[i][j] = 1 - grid[i][j];
              }
                 
              }
        }


        //count the no.of 0s in each column if its grater than 1s count , toggle it

        for(int j = 1; j<n; j++){
            int cnt0 = 0;

            for(int i = 0; i<m; i++){
                if(grid[i][j] == 0){
                    cnt0++;
                }
            }

            int cnt1 = m - cnt0;

            if(cnt0 > cnt1){
                for(int i =0; i<m; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }


        int score = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int val = grid[i][j] * pow(2, n-j-1);
                score += val;
            }
        }

        return score;
    }
};