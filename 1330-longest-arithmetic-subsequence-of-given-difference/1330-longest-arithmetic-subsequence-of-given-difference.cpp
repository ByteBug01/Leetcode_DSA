// class Solution {
// public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//         sort(arr.begin(), arr.end());

//         unordered_map<int, int> mp;

//         for(auto it: arr){
//             mp[it]++;
//         }

//         int cnt = 0;
//         int ans = 0;
//         // for(int i=0; i<arr.size(); i++){
//         //     int x = arr[i] + difference;

//         //     if(mp.find(x) != mp.end()){
//         //         cnt++;
//         //         ans = max(ans, cnt);
//         //     }else{
//         //         cnt--;
//         //     }
//         // }

// int n = arr.size();
//         for(int i =0; i<n; i++){
//             int x = arr[i] + difference;
//             for(int j=i+1; j<n; j++){
//                 if(x == arr[j]) {
//                     x = arr[j] + difference;
//                     cnt++;
//                     ans = max(ans, cnt);
//                 }else{
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
