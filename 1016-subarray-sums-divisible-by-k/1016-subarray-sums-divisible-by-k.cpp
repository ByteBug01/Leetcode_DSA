class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int cnt = 0;
//         // vector<int> cumsum(n, 0);
//         // cumsum[0] = nums[0];
//         for(int i =1; i<n; i++){
//             nums[i] += nums[i-1];
//         }
// int sum =0;
//         for(int i = 0; i<n; i++){
//             for(int j = i; j<n; j++){

//                 sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];
                
//                 if(sum % k == 0){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//tle----------------------------------------------------

             int n = nums.size();

             int ans = 0;

             unordered_map<int,int> mp;

             mp[0] = 1;
             int sum =0 ;
             int cnt =0;

             for(int i =0; i<n; i++){
                sum += nums[i];

              int  rem = sum % k;

                if(rem < 0){
                    rem += k;
                }

                if(mp.find(rem) != mp.end()){ // rem present hai map me
                    cnt += mp[rem];
                }

                mp[rem]++;
             }

             return cnt;

    }
};