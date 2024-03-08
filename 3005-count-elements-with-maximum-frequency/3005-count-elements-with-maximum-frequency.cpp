class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int m = 0;
        // int cnt = 0;
        int mfof = 0;
        for(auto i: mp){
           
                m = max(m, i.second);
            
        }
        
        for(auto j : mp){
            if(j.second == m){
                mfof++;
            }
        }
        
        return m*mfof;
    }
};