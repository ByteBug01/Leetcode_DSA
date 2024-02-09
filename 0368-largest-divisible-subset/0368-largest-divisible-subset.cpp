// class Solution {
// public:
//     //DP LIS

// void solve(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev){
//     if(idx >= nums.size()){
//         if(temp.size() > result.size()){
//             result = temp;
//         }
//         return;
//     }
    
//     //take
//     if(prev == -1 || nums[idx] % prev == 0){
//         temp.push_back(nums[idx]);
//     solve(idx + 1, nums, result, temp, nums[idx]);
        
//         temp.pop_back();
        
//     }
    
//     // not take
    
//     solve(idx, nums, result, temp, prev);

// }
    
    
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
        
//         vector<int> result;
//         vector<int> temp;
        
//         int prev = -1;
        
//       solve(0, nums , result, temp, prev );
        
//         return result;
//     }
// };


//Bottom up LIS

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while(last_chosen_index >= 0) {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};
