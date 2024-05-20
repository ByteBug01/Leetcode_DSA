
// class Solution {
// public:

// // kahn's algo , toposort using bfs

//    bool topoSortCheck(unordered_map<int, vector<int>> adj, int numCourses,  vector<int> & indegree){
//  int n = numCourses;
//         queue<int> q;
//         int cnt = 0;

//         for(int i = 0; i<n; i++){
//                 if (indegree[i] == 0){
//                     q.push(i);
//                     cnt++;
//                  }
//         }

// while(!q.empty()){
//     int u = q.front();
//     q.pop();

//     for(auto & v: adj[u]){

//         indegree[v]--;

//         if(indegree[v] == 0){
//             q.push(v);

//             cnt++;
//         }
//     }
// }

// if(cnt == n){ // if cnt equal to no. of nodes then no cycle
//     return true;
// }

// return false;
//    }
    
  
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

//         unordered_map<int, vector<int>> adj;
//         vector<int> indegree(numCourses, false);
        
//         for(auto& num : prerequisites){
//             int a = num[0];
//             int b = num[1];
            
//             adj[b].push_back(a);
//             indegree[a]++;
//         }
        
//         return topoSortCheck(adj, numCourses, indegree);
//     }
// };

//-----------------------------------------------------------------------------
//using dfs, topocheck
class Solution {
public:

bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }

 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
             unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false;
        }
        
        return true;
 }
};