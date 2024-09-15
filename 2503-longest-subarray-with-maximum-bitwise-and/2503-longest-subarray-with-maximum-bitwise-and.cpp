class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal  =0;
        int  res  =0;
        int streak = 0;

        for(auto& ele: nums){
            if(ele > maxVal){
                maxVal = ele;
                res = 0;
                streak =0;
            }
            if(ele == maxVal){
                streak++;
            }else{
                streak = 0;
            }
            res = max(res, streak);
        }

        return res;
    }
};