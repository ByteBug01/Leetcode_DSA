class Solution {
public:
    int MST(int V, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // minHeap

        pq.push({0, 0});

        vector<bool> inMST(V, false);

        int sum = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (inMST[node] == true) {
                continue;
            }
            inMST[node] = true;
            sum += wt;

            for (auto& ngbr : adj[node]) {
                int ngbr_wt = ngbr.first;
                int ngbr_node = ngbr.second;

                if (!inMST[ngbr_node]) {
                    pq.push({ngbr_wt, ngbr_node});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x2 - x1) + abs(y2 - y1);

                adj[i].push_back({d, j});
                adj[j].push_back({d, i});
            }
        }

        return MST(n, adj);
    }
};
