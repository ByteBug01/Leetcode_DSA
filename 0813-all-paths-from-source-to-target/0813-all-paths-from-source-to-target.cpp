class Solution {
public:

    void dfs(vector<vector<int>>& graph, int u, int goal, vector<vector<int>> & result, vector<int> & temp){
        temp.push_back(u);

        if(u == goal){
            result.push_back(temp);
        }

        for(int & v: graph[u]){
            dfs(graph, v, goal, result, temp); // don't need visited check, as it is directed acyclic graph given
        }

        temp.pop_back(); //goal milne ke baad wapis backtrack krna hai ishliye, pop the node from temp
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int source = 0;
        int target = n-1;

        vector<vector<int>> result;
        vector<int> temp;

        dfs(graph, source, target, result, temp);

        return result;
    }
};