class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxprob(n);

        maxprob[start_node] =  1.0;

        for(int i =0; i<n-1; i++){
            bool update =  false;

            for(int j  = 0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];

                double pathprob = succProb[j];

                if(maxprob[u] * pathprob > maxprob[v]){
                    maxprob[v] = maxprob[u] * pathprob;
                    update = true;
                }

                 if(maxprob[v] * pathprob > maxprob[u]){
                    maxprob[u] = maxprob[v] * pathprob;
                    update = true;
                }
            }

            if(!update) {
                break;
            }
        }

        return maxprob[end_node];
    }
};