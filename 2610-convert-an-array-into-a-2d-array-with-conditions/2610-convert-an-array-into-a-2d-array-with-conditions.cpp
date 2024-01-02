class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
//         int n=0;
//         map<int , int> m;
//         for(auto x: nums){
//             m[x]++;
//             n=max(n, m[x]);
//         }
        
//         vector<vector<int>> ans( n);
//         vector<set<int>> s(n);
        
//         for(auto x: nums){
//             for(int i=0; i<n; i++){
//                 if(s[i].find(x)==s[i].end()){
//                     ans[i].push_back(x);
//                     s[i].insert(x);
//                     break;
//                 }
//             }
//         }
//         return ans;
        
        int n = nums.size();
    
        unordered_map<int, int> mp;
        
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++){
            int freq = mp[nums[i]];
            
            if(freq == result.size()){
                result.push_back({}); //added empty row
            }
            
            result[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }
        
        return result;
    }
};