class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<pair<int, int>, bool> mp;
        
        for(auto it: queens){
            mp[{it[0], it[1]}] = true;
        }
        
        vector<vector<int>>ans;
        
        //top
        for(int i=king[0]; i>=0; i--){
            if(mp.find({i,king[1]})!=mp.end()){
             ans.push_back({i,king[1]});
                break;
            }
        }
        
        //top right
        for(int i = king[0], j = king[1]; i>=0 and j<8; i--, j++){
            if(mp.find({i, j}) != mp.end()){
                ans.push_back({i, j});
                break;
            }
        }
        
        //right
        for(int i=king[1]; i<8; i++){
            if(mp.find({king[0], i}) != mp.end()){
                ans.push_back({king[0], i});
                break;
            }
        }
        
        //bottom right
        for(int i=king[0], j=king[1]; i<8 and j<8; i++, j++){
            if(mp.find({i, j})!=mp.end()){
                ans.push_back({i,j});
                break;
            }
        }
        
        //down
        for(int i=king[0]; i<8; i++){
            if(mp.find({i, king[1]}) != mp.end()){
                ans.push_back({i, king[1]});
                break;
            }
        }
        
        //bottom left
        
        for(int i=king[0], j=king[1]; i<8 and j>=0; i++, j--){
            if(mp.find({i, j}) != mp.end()){
                ans.push_back({i,j});
                break;
            }
        }
        
        //left
        
        for(int i=king[1]; i>=0; i--){
            if(mp.find({king[0], i}) !=mp.end()){
                ans.push_back({king[0], i});
                break;
            }
        }
        //top left
        
        for(int i=king[0], j=king[1]; i>=0 and j>=0; i--, j--){
            if(mp.find({i, j})!= mp.end()){
                ans.push_back({i,j});
                break;
            }
        }
        
        return ans;
    }
};