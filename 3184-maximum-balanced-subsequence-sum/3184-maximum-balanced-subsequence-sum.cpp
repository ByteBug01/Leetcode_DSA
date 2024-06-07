// class Solution {
// public:
// //LIS 
// int n;
// // int t[100001][100001]; esa dp nhi le skte , 10^5 +1 itta store nho ho paega
// //tle
// unordered_map<string, long long> mp;

// long long lis(vector<int>& nums, int prev, int curr_idx){
// if(curr_idx >= n) return 0;

// string key = to_string(prev) + "-" + to_string(curr_idx);
// if(mp.find(key) != mp.end()){
//     return mp[key];
// }


// long long take = INT_MIN, not_take = INT_MIN;

// if(prev == -1 || nums[curr_idx]-curr_idx >= nums[prev] - prev){
//     take = nums[curr_idx] + lis(nums, curr_idx, curr_idx+1);
// }

// not_take = lis(nums, prev, curr_idx+1);



// return mp[key] = max<long long>(take, not_take);

// }
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
// //for TC: nums = [-2,-1], all elements are negative then the ans would be the max element in this array

// int mxele = *max_element(begin(nums), end(nums));

// if(mxele <= 0){
//     return mxele;
// }

// // memset(t, -1, sizeof(t));

//         n =  nums.size();

//         return lis(nums, -1, 0);
//     }
// };

//bottom - up ---------------------------------------------------------------------------------

// class Solution {
// public:

//  long long maxBalancedSubsequenceSum(vector<int>& nums) {
// //for TC: nums = [-2,-1], all elements are negative then the ans would be the max element in this array

// int mxele = *max_element(begin(nums), end(nums));

// if(mxele <= 0){
//     return mxele;
// }

// int n = nums.size();

// vector<long long> t(n);

// for(int i =0; i<n; i++){
//     t[i] = nums[i];
// }

// long long ans = INT_MIN;

// for(int i =0; i<n; i++){
//     for(int j=0; j<i; j++){
//       if(nums[i] - i >= nums[j]-j){
//         t[i] = max<long long>(t[i], t[j] + nums[i]);
//         ans = max<long long>(ans, t[i]);
//       } 
//     }
// }

// return (ans > mxele) ? ans: mxele;
//  }
// };

//-----------------------------------------------------
// memoization, and bottom-up me bhi tle---------------..

//optimal solution--------------------------------------------


class Solution {
public:
//dry run--must
 long long maxBalancedSubsequenceSum(vector<int>& nums) {
    int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
 }
};