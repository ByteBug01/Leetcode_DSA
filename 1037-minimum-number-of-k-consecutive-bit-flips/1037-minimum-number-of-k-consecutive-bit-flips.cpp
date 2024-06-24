class Solution {
public:
//dry run and lookout again
    int minKBitFlips(vector<int>& nums, int k) {
         int n = nums.size();

        int flips = 0;
        int flipBefore = 0;

          vector<bool> isFlipped(n, false);

        for(int i = 0; i < n; i++) {
            if(i >= k && isFlipped[i-k] == true){
                flipBefore--;                     
            }
            
            if(flipBefore % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipBefore++;
                isFlipped[i] = true;
                flips++;
            }
        }

        return flips;
    }
};
