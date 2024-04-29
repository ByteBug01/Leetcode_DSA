class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totXor = 0;
        
        for(auto it: nums){
            totXor ^= it;
        }
        
        int diff = k ^ totXor;   
        
        return __builtin_popcount(diff); //calculates no. of 1's
    }
};