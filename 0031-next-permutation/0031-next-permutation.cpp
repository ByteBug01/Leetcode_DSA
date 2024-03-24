class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n = nums.size(), index = -1;
        // for(int i=n-2; i>=0; i--){
        //     if(nums[i] < nums[i+1]){
        //         index = i;
        //         break;
        //     }
        // }
        // for(int i=n-1; i>=index && index != -1; i--){
        //     if(nums[i] > nums[index]){
        //         swap(nums[i], nums[index]);
        //         break;
        //     }
        // }
        // reverse(nums.begin() + index + 1, nums.end());
        
        
        int n = nums.size();
        
        int gola_idx = -1;
        
        for(int i = n-1; i>0; i--){ //..
            if(nums[i] > nums[i-1]){
                gola_idx = i-1;
                break;
            }
        }
        
        
        if(gola_idx != -1){
            
        int swap_idx = gola_idx;
        
        for(int i = n-1; i>= gola_idx+1; i--){ //remember
            if(nums[i] > nums[gola_idx]){
                swap_idx = i;
                break;
            }
        }
        swap(nums[gola_idx], nums[swap_idx]);
        }
        
        reverse(nums.begin() + gola_idx + 1, nums.end());
        
    }
};