class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(auto num: nums){
           mp[num]++;
        }
        
        int ans;
        for(auto & it: mp){
            if(it.second == 1){
                 ans = it.first;
            }
        }
        return ans;
    }
};