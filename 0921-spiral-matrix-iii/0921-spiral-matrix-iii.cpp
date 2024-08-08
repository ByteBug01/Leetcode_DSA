class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0,1}, {1,0}, {0,-1}, {-1,0}};

        vector<vector<int>> res;

        for(int step = 1, direc = 0; res.size()<rows*cols;){
             for(int i  = 0; i< 2; i++){
                for(int j = 0; j<step; j++){
                    if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                        res.push_back({rStart, cStart});
                    }
                        rStart += dir[direc][0];
                        cStart += dir[direc][1];


                }

                        direc = (direc + 1) % 4;

             }

             step++;
        }

        return res;
    }
};