class Solution {
public:
    void set(int i, vector<int> &nums, vector<int>v, vector<vector<int>> & ans){
         if(i==nums.size())
             return;
         
         v.push_back(nums[i]);
         ans.push_back(v);
         for(int j=i+1; j<nums.size(); j++){
             set(j,nums,v,ans);
         }
     }
    
    
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        ans.push_back(v);
        for(int i=0; i<nums.size(); i++){
            set(i,nums, v, ans);
        }
        return ans;
    }
};