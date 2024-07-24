class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<tuple<int, int, int>> p;

        for (auto& it : points) {
            int x = it[0] * it[0] + it[1] * it[1];
            p.push_back(make_tuple(x, it[0], it[1]));
        }

        sort(p.begin(), p.end());

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back({ get<1>(p[i]), get<2>(p[i]) });
        }

        return ans;
    }
};