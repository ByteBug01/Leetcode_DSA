class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n  = nums.size();
        int duplicate = -1;
        int missing = -1;
            
            vector<int> v(n+1, 0);
 
        for(int i = 0; i<n; i++){
            v[nums[i]]++;
        }
        
        for(int i = 0; i<v.size(); i++){
            if(v[i]>1) duplicate = i;
            if(v[i] == 0 ) missing = i;
        }
        
        return {duplicate, missing};
    }
};