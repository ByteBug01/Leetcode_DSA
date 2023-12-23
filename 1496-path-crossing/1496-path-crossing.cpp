class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> direction;
        
        direction['N'] =  {0, 1};
        direction['E'] =  {1, 0};
        direction['S'] =  {0, -1};
        direction['W'] =  {-1, 0};
        
        unordered_set<string> visited;
        visited.insert("0,0");
        
        int x=0;
        int y=0;
        
        for(char c: path){
            pair<int, int> curr = direction[c];
           int  x_ = curr.first;
            int y_ = curr.second;
            
            x += x_;
            y += y_;
            
            string h = to_string(x) + "," + to_string(y);
            if(visited.find(h) != visited.end()){
                return true;
            }
            
            visited.insert(h);
        }
        
        return false;
    }
};