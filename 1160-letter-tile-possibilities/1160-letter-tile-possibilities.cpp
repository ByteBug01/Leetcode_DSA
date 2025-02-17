class Solution {
public:


void recur(string tiles, unordered_set<string>& sq,vector<bool> &check, string curr){
    sq.insert(curr);

    for(int i = 0; i<tiles.length(); i++){
        if(!check[i]){
            check[i] = 1;
            recur(tiles, sq, check, curr+tiles[i]);
            check[i] = 0;
        }
    }
    
}


    int numTilePossibilities(string tiles) {
        int n  =  tiles.size();
        unordered_set<string> seq;
        vector<bool> check(n, 0);

        recur(tiles, seq, check, "");

        return seq.size()-1;
    
    }
};