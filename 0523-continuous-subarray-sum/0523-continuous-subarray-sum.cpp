class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

unordered_map<int, int> mp;
mp[0] = -1;
    int sum= 0;
 for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;

            if (mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] > 1) { // Check if the subarray length is at least 2
                    return true;
                }
            } else {
                mp[remainder] = i; // Update map only if remainder is not already in the map
            }
        }

        return false;
    }
};