// class Solution {
// public:
// ---------------using vector only and sorting it-----------------------------------
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         int n = heights.size();

//         vector<pair<int, string>> v;

//         for(int i = 0; i<n; i++){
//             v.push_back({heights[i], names[i]});
//         }

//         sort(v.begin(), v.end(), greater<>());

//         vector<string> ans;

//         for(int i =0; i<n; i++){
//             ans.push_back(v[i].second);
//         }

//         return ans;

//     }
// };

class Solution {
public:
// using ordered map--------------------------------------------
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n  =  heights.size();

        map<int, string> mp;

        for(int i = 0; i<n; i++){
            mp[heights[i]] = names[i];
        }

    vector<string> ans(n);

    int i = n -1;

    for(auto & it: mp){
        ans[i] = it.second;
        i--;
    }

    return ans;

    }
};