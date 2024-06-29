// class Solution {
// public:

// void dfs(int ancestor,unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& ancestors) {
//         for (int v : adj[currNode]) {
//             if (ancestors[v].empty() || ancestors[v].back() != ancestor) {
//                 ancestors[v].push_back(ancestor);
//                 dfs(ancestor, adj, v, ancestors);
//             }
//         }
// }


//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> adj;

//         for(auto & edge: edges){
//             int u = edge[0];
//             int v  = edge[1];

//             adj[u].push_back(v);
//         }

//       vector<vector<int>> ances(n);

//         for(int i  = 0; i<n; i++){
//             dfs(i, adj, i, ances); //first  i  = ancestor, 2nd i  =curr_node
//         }

//         return ances;
//     }
// };

//-----------2nd approach by reversing the graph and easy dfs-------------------------------

class Solution {
public:

void dfs(int u,  unordered_map<int, vector<int>> &adj, vector<bool>& visited)
{
    visited[u] = true;

    for(int & v: adj[u]){
        if(!visited[v]){
            dfs(v, adj, visited);
        }
    }
}



 vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto & edge: edges){
            int u = edge[0];
            int v  = edge[1];

            adj[v].push_back(u); // v ---> u, child to parent
        }

vector<vector<int>> ans;

for(int u = 0; u<n; u++){

    vector<int> ancestors;
    vector<bool> visited(n, false);
    dfs(u, adj, visited);

    for(int i = 0; i<n; i++){
        if(i == u) continue; //as node cannot be ancestor of itself

        if(visited[i] == true){
            ancestors.push_back(i);
        }
    }
 ans.push_back(ancestors);
}

return ans;
 }
};