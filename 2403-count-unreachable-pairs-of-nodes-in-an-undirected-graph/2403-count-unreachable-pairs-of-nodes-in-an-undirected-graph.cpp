class Solution {
public:
//step 1: find and Union

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

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i<n; i++){
            parent[i]  = i;
        }

//step 2: components bnao
        for(auto & vec: edges){
            Union(vec[0], vec[1]);
        }

//step 3: map bnao jispe store kro "leaders or parent[component] -> size of component"

unordered_map<int, int> mp;

        for(int i = 0; i<n; i++){
            int leader = find(i);
            mp[leader]++;
        }

        // step 4: mp se ans nikalo
long long ans = 0;
long long remainingnodes = n;

        for(auto& it : mp){
            int size = it.second; //component ki size
            //formula lgao

            ans += size * (remainingnodes - size); //logic by dryrun observation
            remainingnodes -= size;
        }

return ans;
    }
};