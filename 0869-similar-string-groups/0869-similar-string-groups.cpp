// class Solution {
// public:

//     bool similar(string s1, string s2){
        
//         int n1 = s1.length();
//         int n2 = s2.length();

//         if(n1 != n2){
//             return false;
//         }

//         int cntDiff = 0;

//         for(int i = 0; i<n1; i++){
//             if(s1[i] != s2[i]){
//             cntDiff++;
//             }
//         }

//         return cntDiff == 2 || cntDiff == 0;
//     }

//     //-------through dfs----------------
 
// //    void dfs(unordered_map<int, vector<int>> adj, vector<bool>& visited, int u){
// //     visited[u] =  true;

// //     for(int & v: adj[u]){
// //         if(!visited[v]){
// //             dfs(adj, visited, v);
// //         }
// //     }
// //    }

// // ---------------through bfs-----------------------

// void bfs( unordered_map<int, vector<int>> adj, int u, vector<bool>& visited){
//     queue<int> q;

//     q.push(u);
//     visited[u] = true;

//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
          
//           for(int & v: adj[node]){
//             if(!visited[v]){
//                 q.push(v);
//                 visited[v] = true;
//             }
//           }

//     }
// }


//     int numSimilarGroups(vector<string>& strs) {
//         int n = strs.size();

//         unordered_map<int, vector<int>> adj;

//         for(int i = 0; i<n-1; i++){
//             for(int j = 0; j<n; j++){
//                 if(similar(strs[i], strs[j])){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//        vector<bool> visited(n, false);
//        int ans = 0;

//        for(int i =0; i<n; i++){
//         if(!visited[i]){
//             // dfs(adj, visited, i);
//             bfs(adj, i, visited);
//             ans++;
//         }
//        }

//        return ans;
//     }
// };

//---------------through dsu(union, find)-------------------------------------
class Solution {
public:

vector<int> parent;
vector<int> rank;

int find(int i){
    if( i == parent[i]){
        return i;
    }

    return parent[i] = find(parent[i]);
}


void Union(int x, int y){
    int x_p = find(x);
    int y_p = find(y);

    if(x_p == y_p){
        return;
    }

    if(rank[x_p] > rank[y_p]){
        parent[y_p] = x_p;
    }else if(rank[y_p] > rank[x_p]){
        parent[x_p] = y_p;
    }else{
        parent[x_p] = y_p;
        rank[y_p]++;
    }
}

    bool similar(string s1, string s2){
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 != n2){
            return false;
        }

        int cntDiff = 0;

        for(int i = 0; i<n1; i++){
            if(s1[i] != s2[i]){
            cntDiff++;
            }
        }

        return cntDiff == 2 || cntDiff == 0;
    }

      int numSimilarGroups(vector<string>& strs) {
              int n = strs.size();

              parent.resize(n);
              rank.resize(n, 0);

              for(int i = 0; i<n; i++){
                parent[i] = i;
              }

             int componentCnt = n;

              for(int i =  0; i<n-1; i++){
                for(int  j= i+1; j<n; j++){
                    if(similar(strs[i], strs[j]) && find(i) != find(j)){ //find(i) != find(j) , this means that both don't belong to same group
                        Union(i, j);
                        componentCnt--;
                    }
                }
              }

              return componentCnt;
      }
};



