class Solution {
public:
    
    // problem converted into "number of subarrrays with sum k"........
    int numberOfSubarrays(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
         int oddCnt =0;
         int ans = 0;

         mp[oddCnt] = 1;

         for(auto & it: nums){
            oddCnt += (it%2);

            if(mp.find(oddCnt - k) != mp.end()){
                ans += mp[oddCnt - k];
            }

            mp[oddCnt] ++;
         }

         return ans;
    }
};