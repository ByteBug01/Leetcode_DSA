class Solution {
public:

// bool search(int index, int i, int j, vector<vector<char>>& board, string word){
//     if(index == word.size()){
//         return true;
//     }
//     if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
//     {
//         return false;
//     }
//     bool ans = false;
//     if(word[index] == board[i][j]){
//         board[i][j] = '*';

//         ans= search(index+1, i+1, j, board, word) or
//         search(index+1, i, j+1, board, word) or
//         search(index+1, i-1, j,board, word)or
//         search(index+1, i, j-1, board, word);
//         board[i][j] = word[index];
//     }
//     return ans;
// }


//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board[0].size();
//         int n= board.size();
//         int index = 0;
//         bool ans = false;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m ; j++){
//                 if(word[index]== board[i][j]){
//                     if(search(index,i,j,board, word))
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
    
    //BACKTRACKING------------------------------------------//
    
    int n , m;
    int l ;
    
    vector<vector<int>> directions = { {1,0}, {0,1}, {-1, 0}, {0,-1}};
    
    bool find(vector<vector<char>>& board, int i , int j , int idx, string & word)
    {
         if(idx >= l)
            return true;
        
         if(i <0 || j<0 || i>=n || j>=m || board[i][j] == '$'){
            return false;
        }
        
        if(board[i][j] != word[idx]){
            return false;
        }
        
        if(idx == word.size()){
            return true;
        }
        
        char temp = board[i][j];
        board[i][j] = '$'; 
        //agr hum curr word letter ko visit kr liye toh usee '$' assign krdenge so that wapis se previous             direction me na aaye
        
        for(auto& it: directions){
           int  new_i = i + it[0];
           int  new_j = j + it[1];
            
            if( find(board, new_i, new_j, idx+1, word) ){
                return true;
            }
        }
        
         board[i][j]  = temp;
        
        return false;
    }
    
    
     bool exist(vector<vector<char>>& board, string word) {
          n = board.size();
          m = board[0].size();
         l = word.size();
         
         if(m*n < l){
             return false;
         }
         
         for(int i = 0; i<n; i++){
             for(int j = 0; j<m; j++){
                 if(board[i][j] == word[0] && find(board, i, j, 0, word)){
                     return true;
                 }
             }
         }
         return false;
     }
};