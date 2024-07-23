class Solution {
public:

static bool compare(pair<int, int> a, pair<int, int> b){ //remember to use "static"
    if(a.second == b.second)
       return a.first > b.first;

       return a.second < b.second;
}
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(auto & it: nums){
            mp[it]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());
        
        sort(v.begin(), v.end(), compare);

        vector<int> ans;

        for(auto & p: v){
            for(int i = 0; i<p.second; i++){
                    ans.push_back(p.first);
            }
        }

return ans;
    }
};