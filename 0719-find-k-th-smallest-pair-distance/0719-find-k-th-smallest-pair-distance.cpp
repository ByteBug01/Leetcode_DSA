class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        int x = *max_element(nums.begin(), nums.end());

        vector<int> v(x+1, 0);

        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int dis = v[abs(nums[j] - nums[i])]++;
              
            }
        }

        for(int d = 0; d < x; d++){
            k -= v[d];
            if(k <= 0){
                return d;
            }
        }

        return -1;
    }
};