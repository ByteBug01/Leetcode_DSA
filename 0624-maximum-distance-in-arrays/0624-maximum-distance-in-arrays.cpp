class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
//not working--------------------------

        // int n = arrays.size();
        
        // vector<pair<int, int>> v;

        // for(int i=0; i<n; i++){
        //     vector<int> temp = arrays[i];

        //     for(int j = 0; j<temp.size(); j++){
        //         v.push_back({temp[j], i});
        //     }
        // }

        // sort(v.begin(), v.end());

        // int mini = INT_MAX;
        // int maxi = INT_MIN;

        // vector<int> visited(v.size(), 0);

        // for(int i = 0; i<v.size(); i++){
        //      if(!visited[i]){
        //         mini = min(mini, v[i]);
        //         visited[i] = 1;
        //      }

        //      if(!visited[n-i-1]){
        //         maxi = max(maxi, v[n-i-1]);
        //         visited[n-i-1] = 1;
        //      }
        // }

        // return maxi - mini;


        int n = arrays.size();

        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        int ans = 0;

        for(int i = 1; i <n; i++){
               ans = max(ans, max(abs(maxi - arrays[i][0]), abs(arrays[i].back() - mini)));

               mini = min(mini, arrays[i][0]);
               maxi = max(maxi, arrays[i].back());

        }

        return ans;
    }
};