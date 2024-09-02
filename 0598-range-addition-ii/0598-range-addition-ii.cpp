// class Solution {
// public:
//     int maxCount(int m, int n, vector<vector<int>>& ops) {
//         int t = ops.size();

//         vector<vector<int>> matrix(m, vector<int>(n, 0));

//          int i =0;
//          int max_ele = 0;

//         while(t--){
//             int a = ops[i][0];
//             int b = ops[i][1];

//             for(int i= 0; i<a; i++){
//                 for(int j = 0; j<b; j++){
//                     matrix[i][j] += 1;
//                     max_ele = max(max_ele, matrix[i][j]);
//                 }
//             }
//         }

// int cnt = 0;
// for(int i  =0; i<m; i++){
//     for(int j  =0; j<n; j++){
//              if(matrix[i][j] == max_ele){
//                 cnt++;
//              }
//     }
// }

// return cnt;

//     }
// };

//--------this is bkar bruteforce,, apply logic,, why doing everthing thats mention in the problem to do
//the maximum value in the matrix will be located in the smallest submatrix that was incremented the most times

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a_min = m;
        int b_min = n;

        for(auto it: ops){
            a_min = min(a_min, it[0]);
            b_min = min(b_min, it[1]);
        }

        return (a_min * b_min);
    }
};      