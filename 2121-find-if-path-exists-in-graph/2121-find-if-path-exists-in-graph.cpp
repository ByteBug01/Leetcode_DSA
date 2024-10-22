class Solution {
public:

        bool dfs(int strt, int end, unordered_map<int, vector<int>> &mp, vector<bool> &visited){
            if(strt == end) return true;

            if(visited[strt]) return false;

            visited[strt] = true;

            for(auto it: mp[strt]){
                if(dfs(it, end, mp, visited)) return true;
            }

            return false;
        }

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {

       unordered_map<int, vector<int>> mp;
       vector<bool> visited(n, false); 
      
      for(auto & it: edges){
        int u = it[0];
        int v = it[1];

        mp[u].push_back(v);
        mp[v].push_back(u);
      }

      
    return dfs(start, end, mp, visited);
    }
};