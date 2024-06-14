// class Solution {
// public:
//     int numberOfArithmeticSlices(std::vector<int>& nums) {
//         int n = nums.size();
//         int totalCount = 0;

     
//         vector<unordered_map<long long, int>> dp(n);

//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 long long diff = (long long)nums[i] - nums[j];

              
//                 if (diff < INT_MIN || diff > INT_MAX)
//                     continue;

//                 int count = dp[j].count(diff) ? dp[j][diff] : 0;

                
//                 totalCount += count;
//                 dp[i][diff] += count + 1;
//             }
//         }

//         return totalCount;
//     }
// };

class Solution {
 public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
         int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];//array of map

        for(int i =0; i<n; i++){
            for(int j = 0; j<i; j++){
               auto diff = (long)nums[i]-nums[j];

                auto it = mp[j].find(diff); //dekhenge ki j pe end hone wala diff hai ya nhi

                 int count_at_j = it==end(mp[j]) ? 0 : it->second; //agr j pe end hone wala diff hai ya nhi hai toh 0 count other wise kitte j pe end hone wale hai wo

                 mp[i][diff] += count_at_j+1;
                result      += count_at_j;
            }
        }
        return result;
    }
};