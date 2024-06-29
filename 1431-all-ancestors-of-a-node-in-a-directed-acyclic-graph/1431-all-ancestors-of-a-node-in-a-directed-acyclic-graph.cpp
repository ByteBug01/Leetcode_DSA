class Solution {
public:

void dfs(int ancestor,unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& ancestors) {
        for (int v : adj[currNode]) {
            if (ancestors[v].empty() || ancestors[v].back() != ancestor) {
                ancestors[v].push_back(ancestor);
                dfs(ancestor, adj, v, ancestors);
            }
        }
}


    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto & edge: edges){
            int u = edge[0];
            int v  = edge[1];

            adj[u].push_back(v);
        }

vector<vector<int>> ances(n);

        for(int i  = 0; i<n; i++){
            dfs(i, adj, i, ances); //first  i  = ancestor, 2nd i  =curr_node
        }

        return ances;
    }
};