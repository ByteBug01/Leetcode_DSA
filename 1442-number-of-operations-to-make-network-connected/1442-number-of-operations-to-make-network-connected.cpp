class Solution {
public:

//using DSU

vector<int> parent;
vector<int> rank;

int find(int i){
    if(i != parent[i])
    return parent[i] = find(parent[i]);


    return parent[i];
}

void Union(int x, int y){

int p_x = find(x);
int p_y = find(y);

if(p_x != p_y){
    if(rank[p_x] > rank[p_y]){
        parent[p_y] = p_x;
    }else if(rank[p_x] < rank[p_y]){
        parent[p_x] = p_y;
    }else{
        parent[p_x] = p_y;
        rank[p_y]++;
    }
}
}

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1){
            return -1;
        }
         parent.resize(n);
         rank.resize(n, 0);

        for(int i  =0; i<n; i++){
            parent[i] = i;

        }
        int components = n; //at starting all nodes are independent

        for(auto & num : connections){

            if(find(num[0]) != find(num[1])){
                Union(num[0], num[1]); // we continue to build connections
                components--;
            }
        }

        return components - 1;
    }
};