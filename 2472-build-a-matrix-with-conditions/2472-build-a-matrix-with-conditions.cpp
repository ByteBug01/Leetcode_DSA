class Solution {
public:

//-----------------topo Sort by dfs---------------------------------------------
    // void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& visited, stack<int>& st, bool& cycle) {
    //     visited[u] = 1; // Mark the node as visiting

    //     for (auto& v : adj[u]) {
    //         if (visited[v] == 0) {
    //             dfs(v, adj, visited, st, cycle);
    //         } else if (visited[v] == 1) {
    //             cycle = true; // Cycle detected
    //             return;
    //         }
    //     }

    //     visited[u] = 2; // Mark the node as visited
    //     st.push(u); 
    // }

    // vector<int> topo(int k, vector<vector<int>>& condition) {
    //     vector<int> order;
    //     unordered_map<int, vector<int>> adj;

    //     for (auto& it : condition) {
    //         int u = it[0];
    //         int v = it[1];
    //         adj[u].push_back(v);
    //     }

    //     vector<int> visited(k + 1, 0);
    //     stack<int> st;
    //     bool cycle = false;

    //     for (int i = 1; i <= k; i++) {
    //         if (visited[i] == 0) {
    //             dfs(i, adj, visited, st, cycle);
    //             if (cycle) {
    //                 return {};
    //             }
    //         }
    //     }

    //     while (!st.empty()) {
    //         order.push_back(st.top());
    //         st.pop();
    //     }

    //     return order;
    // }

    //-----------------------topo SOrt by BFS--------------------------------------------
   vector<int> topo(int k, vector<vector<int>>& conditions) {
        unordered_map<int, vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);

        for (vector<int>& edge : conditions) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        int cnt = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            cnt++;

            for (auto& v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (cnt != k) {
            return {}; // cycle detected, not all nodes were visited
        }

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topo(k, rowConditions);
        vector<int> topoCol = topo(k, colConditions);

        if (topoRow.empty() || topoCol.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (topoRow[i] == topoCol[j]) {
                    matrix[i][j] = topoRow[i];
                }
            }
        }

        return matrix;
    }
};
