// class Solution {
// public:

// void dfs( unordered_map<int, vector<int>> adj, int u, vector<bool>& visited){
// visited[u] = true;

// for(auto & v : adj[u]){
//     if(!visited[v]){
//         dfs(adj, v, visited);
//     }
// }

// }


// int findCircleNum(vector<vector<int>>& isConnected) {

//     int n = isConnected.size();

//    unordered_map<int, vector<int>> adj;

//    for(int i = 0; i<n; i++){
//     for(int j = 0; j<n; j++){
//         if(isConnected[i][j] == 1){
//             adj[i].push_back(j);
//             adj[j].push_back(i);
//         }
//     }
//    }

//    vector<bool> visited(n, false);

//    int cnt  = 0;

//    for(int i =0; i<n; i++){
//     for(auto & v: adj[i]){
//         if(!visited[v] ){
//             dfs(adj, i, visited);
//             cnt++;
//         }
//     }
//    }

// return cnt;

// }
// };

//--------------------------------------------------------------------------
//bfs
// class Solution {
// public:
// int n;
// void bfs(vector<vector<int>>& isConnected, int u , vector<bool> & visited){
// queue<int> q;
// q.push(u);

// visited[u] = true;

// while(!q.empty()){
//  int curr = q.front();
//  q.pop();

//  for(int v = 0; v<n; v++){
//      if(!visited[v] && isConnected[u][v] == 1){
//         bfs(isConnected, v, visited);

//      }
//  }

// }

// }


// int findCircleNum(vector<vector<int>>& isConnected) {
//     n = isConnected.size();

//    vector<bool> visited(n, false);

//    int cnt  = 0;

//    for(int  i = 0; i<n ;i++){
//     if(!visited[i]){
//         bfs(isConnected, i, visited);
//         cnt++;
//     }
//    }

// return cnt;
// }
// };

//--------------------04/18------

class Solution {
public:

void dfs(int i, vector<bool>& visited, unordered_map<int, vector<int>>& adj){
    visited[i] = true;

    for(auto & it: adj[i]){
        if(!visited[it]){
            dfs(it, visited, adj);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();

      unordered_map<int, vector<int>> adj;

      for(int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
              if(isConnected[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
              }
        }
      }

        vector<bool>visited(n, false);
        int provinceCnt =  0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                provinceCnt++;
            }
           
        }
         return provinceCnt;
      

     
}
};


