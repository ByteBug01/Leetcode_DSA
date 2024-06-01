class Solution {
public:

// rooms given is just as adjacency list..
// if any node is left unvisited then return false
// simply do dfs
    void dfs(vector<vector<int>>& rooms, int u, vector<bool> & visited){
        visited[u] = true;

        for(int & v: rooms[u]){
            if(!visited[v]){
                dfs(rooms, v, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, 0, visited);

        for(int x: visited){
            if(x == false){
                return false;
            }
        }

        return true;
    }
};