class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n =  nums.size();

        int singleSum = 0;
        int totSum  =0;

        for(int i = 0; i<n; i++){
            totSum += nums[i];
            if(nums[i] >= 1 && nums[i] <10){
                singleSum += nums[i];
            }
        }

        if((totSum - singleSum) == singleSum){
            return false;
        }

        return true;
    }
};