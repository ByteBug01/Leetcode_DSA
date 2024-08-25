class Solution {
public:
    pair<int, int> ismin(vector<int>& nums) {
        int mini = nums[0];
        int idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                idx = i;
            }
        }
        return {mini, idx};
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            pair<int, int> x = ismin(nums);
            int ele = x.first;
            int idx = x.second;
            nums[idx] = ele * multiplier;
        }

        return nums;
    }
};
