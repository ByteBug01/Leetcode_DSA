class Solution {
public:

// first find min in each row, then find max in each col, then find ele which is both
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m  = matrix.size(); //row
        int n  = matrix[0].size(); // col

        vector<int> ans;

vector<int> rMin(m);
        for(int i =0; i<m; i++){
            int rowMin = matrix[i][0];

            for(int j  =1; j<n; j++){
                if(matrix[i][j] < rowMin){
                     rowMin = matrix[i][j];
                }
            }
            rMin[i] = rowMin;
        }


        vector<int> cMax(n);
        for(int j=0; j<n; j++){
            int colMax = matrix[0][j];

            for(int i  =1; i<m; i++){
                if(matrix[i][j] > colMax){
                     colMax = matrix[i][j];
                }
            }
            cMax[j] = colMax;
        }


        for(int  i =0; i<m; i++){
            for(int j  =0; j<n; j++){
                if(matrix[i][j] == rMin[i] && matrix[i][j] == cMax[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};