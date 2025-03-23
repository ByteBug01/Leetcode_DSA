class Solution {
public:
int mod= 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto & it: roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
     

    vector<long long> result(n, LLONG_MAX);
    vector<int> countPath(n, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //min_heap,,, we wanted min count

    result[0] =  0;
    countPath[0] = 1;
    pq.push({0,0}); //node, time

    while(!pq.empty()){
        long long currTime = pq.top().first;
        int currNode  = pq.top().second;
    pq.pop();

        for(auto & v: adj[currNode]){
            int ngbr = v.first;
            long long time = v.second;

            if(currTime + time < result[ngbr]){
                result[ngbr] = currTime + time;
                pq.push({ result[ngbr], ngbr});
                countPath[ngbr] = countPath[currNode];
            }else if(currTime + time == result[ngbr]) {
                countPath[ngbr]  = (countPath[ngbr] + countPath[currNode]) % mod;
            }
           

        }
    }

return countPath[n-1];

    }
};