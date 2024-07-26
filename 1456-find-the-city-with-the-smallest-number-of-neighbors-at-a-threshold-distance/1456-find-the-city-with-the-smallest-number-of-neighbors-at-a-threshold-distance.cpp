
class Solution {
public:
    typedef pair<int, int> p;

    int find(int n, vector<vector<int>>& spm, int d) {
        int ansCity = -1;
        int leastCnt = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cntReach = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && spm[i][j] <= d) {
                    cntReach++;
                }
            }

            if (cntReach <= leastCnt) {
                leastCnt = cntReach;
                ansCity = i;
            }
        }

        return ansCity;
    }

    void dijkstra(int n, unordered_map<int, vector<p>>& adj, vector<int>& result, int s) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, s});
        fill(result.begin(), result.end(), INT_MAX);
        result[s] = 0;  // Distance to source itself is zero

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& pt : adj[node]) {
                int adjNode = pt.first;
                int dist = pt.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> spm(n, vector<int>(n, INT_MAX)); //shortest path matrix

        for (int i = 0; i < n; i++) {
            spm[i][i] = 0;
        }

        unordered_map<int, vector<p>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for (int i = 0; i < n; i++) {
            vector<int> result(n, INT_MAX);
            dijkstra(n, adj, result, i);
            spm[i] = result;
        }

        return find(n, spm, distanceThreshold);
    }
};
