class Solution {
public:
// The center node has a degree of N-1, and all other nodes have a degree of 1.
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;

        for(auto & edge:  edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for(auto & it: degree){
            if(it.second == edges.size()){
                return it.first;
            }
        }

        return -1;
    }
};