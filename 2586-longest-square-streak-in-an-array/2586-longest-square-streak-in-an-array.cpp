// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         int n =  nums.size();
//         sort(nums.begin(), nums.end());
//         int maxlen = -1;
//         unordered_set<int> sett(nums.begin(), nums.end());

//         for(int i  =0; i<n-1; i++){
//            int len = 1;
//            long long curr = nums[i];

//         //    for(int j = i+1; j<n; j++){
//         //       if(nums[j] == curr * curr)
//         //         {len++;
//         //         curr = nums[j];}
//         //       else if(nums[j] > curr * curr){ break;}
//         //    }

//         while(sett.count(curr*curr)){
//             len++;
//             curr *=curr;

//             if(curr > INT_MAX) break;
//         }

//            if(len >= 2) maxlen = max(maxlen, len);
//         }

//         return maxlen;
//     }
// };


// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         unordered_set<int> numSet(nums.begin(), nums.end());
        
//         int maxlen = -1;

//         for (int num : nums) {
//             int len = 1;
//             long long current = num;

//             while (numSet.find((int) current) != numSet.end())) {
//                 len++;
//                 current *= current;
//                 if (current > INT_MAX) break;
//             }

//             if (len >= 2) {
//                 maxlen = max(maxlen, len);
//             }
//         }

//          return maxlen <2? -1 : maxlen;
//     }
// };


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ls = 0;
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

        for (int startNumber : nums) {
            int currentStreak = 0;
            long long current = startNumber;

            while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
                currentStreak++;
                if (current * current > 1e5) break;
                current *= current;
            }

            ls = max(ls, currentStreak);
        }

        return ls < 2 ? -1 : ls;
    }
};
