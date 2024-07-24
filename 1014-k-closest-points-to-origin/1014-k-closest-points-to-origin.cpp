// class Solution {
// public:

// // sorting-------------O(nlogn)---------------
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         vector<tuple<int, int, int>> p;

//         for (auto& it : points) {
//             int x = it[0] * it[0] + it[1] * it[1];
//             p.push_back(make_tuple(x, it[0], it[1]));
//         }

//         sort(p.begin(), p.end());

//         vector<vector<int>> ans;

//         for (int i = 0; i < k; i++) {
//             ans.push_back({ get<1>(p[i]), get<2>(p[i]) });
//         }

//         return ans;
//     }
// };

//-----------------using max heap-----------------------------------

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for(auto & it: points){
            int x = it[0]*it[0] + it[1]*it[1];

            if(pq.size() < k){
                pq.push({x, {it[0], it[1]}});
            }else{
                if(x < pq.top().first){
                    pq.pop();
                    pq.push({x, {it[0], it[1]}});
                }
            }
        }
        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};