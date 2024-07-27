class Solution {
public:
    void floyd(vector<vector<long long>>& adj, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Prepare the adjacency matrix
        for (int i = 0; i < original.size(); i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adj[s][t] = min(adj[s][t], (long long)cost[i]);
        }

        // Initialize the diagonal to 0
        for (int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }

        // Apply Floyd-Warshall algorithm
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adj[i][k] < INT_MAX && adj[k][j] < INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX));

        floyd(adj, original, changed, cost);

        long long ans = 0;

        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) {
                continue;
            }

            if (adj[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            ans += adj[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};
