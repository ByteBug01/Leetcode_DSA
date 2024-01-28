class Solution {
public:
    
    // tough, kafi dimk lgane wala.....revisit ....1D ka logic 2D me
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        //row wise cumulative sum
        for(int row = 0; row<r; row++){
            for(int col = 1; col<c; col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }
        
        
        //no. of subarrays with sum ==  target downward direction
        
        int ans = 0;
        for(int strtcol = 0; strtcol < c; strtcol++){
            for(int j =strtcol; j<c; j++){
                unordered_map<int, int> mp;
                mp.insert({0,1});
                int cumsum  = 0;
                
                for(int row = 0; row<r; row++){
                    cumsum += matrix[row][j] - (strtcol > 0 ? matrix[row][strtcol - 1] : 0);
                    
                    if(mp.find(cumsum - target) != mp.end()){
                        ans += mp[cumsum - target];
                    }
                    mp[cumsum]++;
                }
            }
        }
        return ans;
    }
};