class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // int diff = INT_MAX;
        // for(int i=0; i<nums.size()-2;i++){
        //     int newTarget = target - nums[i];
        //     int l= i+1, r = nums.size()-1;
        //     while(l<r){
        //         int sum = nums[l]+nums[r];
        //         diff = abs(diff)>abs(sum-newTarget) ? sum-newTarget : diff;
        //         if(sum<newTarget)
        //             l++;
        //         else
        //             r--;
        //     }
        // }
        // return target + diff;
        
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int closestSum = 100000;
        
        for(int k = 0; k<=n-3; k++){
            
            int i  = k+1; int j = n-1;
            
            while(i<j){
               int sum  = nums[k] + nums[i] + nums[j];
                
                if(abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;
                }
                
                if(sum < target) { i++; }
                else { j--; }
                
            }
        }
        
            return closestSum;
    }
};