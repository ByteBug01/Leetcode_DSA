class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // 2 step se 90degree rotate hoga
        //1. Transpose
        //2. Reverse
        
        // abhi tranpose krenge
        
        //1 2 3   row, col ban jaega //1 4 7
        //4 5 6                      //2 5 8
        //7 8 9                      //3 6 9
        
        // ab we will reverse every row
        
        //1 4 7  ---->   //7 4 1
        //2 5 8          //8 5 2
        //3 6 9          //9 6 3
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Transpose
        for(int i = 0; i<n; i++){
            for(int j = i; j<m; j++){ //remember
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //Reverse
        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};