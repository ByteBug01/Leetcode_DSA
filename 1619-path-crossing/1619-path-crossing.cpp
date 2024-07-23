class Solution {
public:
    bool isPathCrossing(string path) {

        unordered_map< char, pair<int, int>> mp;

        mp['N'] = {0, 1};
        mp['S'] = {0, -1};
        mp['E'] = {1, 0};
        mp['W'] = {-1, 0};

        unordered_set<string> visited;
        visited.insert("0,0");

        int x = 0, y = 0;

        for( char & ch: path){
            pair<int, int> p = mp[ch];

            int dx = p.first;
            int dy = p.second;

            x += dx;
            y += dy;

            string hash = to_string(x) + "," + to_string(y);

            if(visited.find(hash) != visited.end()){
                return true;
            }

            visited.insert(hash);
            
        }

return false;
    
    }
};