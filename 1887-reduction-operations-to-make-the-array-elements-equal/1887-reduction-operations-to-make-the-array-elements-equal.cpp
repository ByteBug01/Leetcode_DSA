class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        int no = 0;
        
        
        for(int i=n-1; i>=1; i--){
            if(nums[i] == nums[i-1]) continue;
            
            no += (n-i);
        }
        
        return no;
    }
};