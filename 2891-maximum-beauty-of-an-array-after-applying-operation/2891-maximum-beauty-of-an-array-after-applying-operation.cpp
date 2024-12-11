class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxBeauty = 0 ;
        int left = 0;

        for(int right =0; right<n; right++){
            while(nums[right] > nums[left] + 2*k){ //key idea: we need overlapped common ele among all ranges
                left++;
            }

            maxBeauty = max(right-left + 1, maxBeauty);
        }

        //range for ele nums[left] = [nums[left]-k, nums[left]+k]
        //range for ele nums[right] = [nums[right]-k, nums[right]+k]
        //These ranges overlap iff: nums[right] - k <= nums[left]+k ==> nums[right] <= nums[left]+2*k

        return maxBeauty;
    }
};