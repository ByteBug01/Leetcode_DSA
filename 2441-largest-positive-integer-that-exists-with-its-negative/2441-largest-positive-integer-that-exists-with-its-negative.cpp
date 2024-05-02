class Solution {
public:
    int findMaxK(vector<int>& nums) {
       int n  = nums.size();
        
        
        vector<int> pos, neg;
        
        for(int i = 0; i<n; i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(abs(nums[i]));
            }
        }
        
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        
        for(int i = pos.size()-1; i>= 0; i--){
            for(int j = neg.size()-1; j>= 0; j--){
                if(pos[i] == neg[j]){
                    return pos[i];
                    break;
                }
            }
        }
        return -1;
    }
};