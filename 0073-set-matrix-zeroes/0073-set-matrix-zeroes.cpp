class Solution {
public:
    void upzero(vector<vector<int>>& dummy, int i, int j) {
        for (int a = i - 1; a >= 0; a--) {
            dummy[a][j] = 0;
        }
    }

    void downzero(vector<vector<int>>& dummy, int i, int j) {
        for (int a = i + 1; a < dummy.size(); a++) {
            dummy[a][j] = 0;
        }
    }

    void leftzero(vector<vector<int>>& dummy, int i, int j) {
        for (int b = j - 1; b >= 0; b--) {
            dummy[i][b] = 0;
        }
    }

    void rightzero(vector<vector<int>>& dummy, int i, int j) {
        for (int b = j + 1; b < dummy[0].size(); b++) {
            dummy[i][b] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dummy = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    upzero(dummy, i, j);
                    downzero(dummy, i, j);
                    leftzero(dummy, i, j);
                    rightzero(dummy, i, j);
                }
            }
        }
        
        matrix = dummy;
        
        // return dummy;
    }
};