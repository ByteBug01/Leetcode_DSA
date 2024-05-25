// class Solution {
// public:

// -------------giving TLE-------------------------------------------------------
//     vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
//        int n = nums.size();
//         int q = queries.size();

//         vector<int> ans;

//         vector<tuple<int, int, int>> v;

//         unordered_map<int, int> mp;

//         for(int i = 0; i < n; i++) {
//             mp[nums[i]]++;
//             v.push_back({nums[i], i, mp[nums[i]]});
//         }

//         for(int i = 0; i < q; i++) {
//             bool found = false;
//             for(auto & it: v) {
//                 if(get<0>(it) == x && get<2>(it) == queries[i]) {
//                     ans.push_back(get<1>(it));
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found) {
//                 ans.push_back(-1);
//             }
//         }

//         return ans;
//     }
// };


 class Solution {
public:

 vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {

 unordered_map<int, vector<int>> occurrences;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occurrences[x].push_back(i);
            }
        }

        vector<int> ans;
        for (int query : queries) {
            if (query > occurrences[x].size()) {
                ans.push_back(-1);
            } else {
                ans.push_back(occurrences[x][query - 1]); //this the main
            }
        }

        return ans;

 }
};