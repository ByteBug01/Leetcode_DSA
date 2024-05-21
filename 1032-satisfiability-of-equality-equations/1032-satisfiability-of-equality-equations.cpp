class Solution {
public:
//using DSU
vector<int> parent;
vector<int> rank;

int find(int x){
    if(x == parent[x]){
        return parent[x];
    }

    return parent[x] = find(parent[x]);
}

// void Union(int x, int y){
//     int x_parent = find(x);
//     int y_parent = find(y);


//     if(x_parent == y_parent){
//         return;
//     }

// if(rank[x_parent] > rank[y_parent]){
//     parent[y_parent] = x_parent;
//  }else if(rank[x_parent] < rank[y_parent]){
//     parent[x_parent] = y_parent;
//  }else{
//    parent[x_parent] = y_parent;
//    rank[y_parent]++;
//  }
// }

 void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i  =0; i<26; i++){
            parent[i]  =i;
            rank[i] = 1;
        }

         for(string &s : equations) {
            if(s[1] == '=')
                Union(s[0]-'a', s[3]-'a');
        }
        
        for(string &s : equations) {
            if(s[1] == '!') {
                if(find(s[0]-'a') == find(s[3]-'a'))
                    return false;
            }
        }
        
        return true;
    }
};