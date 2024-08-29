class Solution {
public:

int n;
void dfs(vector<vector<int>>& stones, int ind,   vector<bool>& visited){
    visited[ind] = true;

    for(int  i  =0; i<n; i++){
          int r = stones[ind][0];
          int c = stones[ind][1];

          if(!visited[i] && (stones[i][0] == r ||stones[i][1] == c)){
            dfs(stones, i, visited);
          }
    }
}

    int removeStones(vector<vector<int>>& stones) {
         n = stones.size();
        vector<bool> visited(n, false);

int group = 0;

for(int i =0; i<n; i++){
    if(visited[i] == true){ //skip
        continue;
    }
    
    dfs(stones, i, visited);
        group++;
}


      return n - group;  
    }
};