class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n  =nums.size();
        int cnt = 0;
        int j = 0;
        for(int i =0; i<n; i++){
             if(nums[i] == 0){ 
                cnt++;
                }
               else{
                 nums[j] = nums[i];
                 j++; 
               }
        }

     for(int i = j; i<n; i++){
        nums[i] = 0;
     }
        
    }
};