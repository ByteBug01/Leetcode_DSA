class Solution {
public:
//dijkstra-----------------------
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;

        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> res(n, 0);
        res[start] = 1.0;
        pq.push({1.0, start});

        while(!pq.empty()){
            int curr = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto ngbr: adj[curr]){
                int node = ngbr.first;
                double nodeProb = ngbr.second;

                if(res[node] < currProb*nodeProb){
                    res[node] = currProb*nodeProb;
                    pq.push({res[node], node});
                }
            }
        }

        return res[end];
    }
};