class Solution {
public:
    

    int solve(vector<int>& nums){
         
         sort(nums.begin(), nums.end());

        int l = 0; int r = nums.size()-1;

        while(l <= r){
            int mid = l +(r-l)/2;

            if(nums[mid] > mid ){
                r = mid-1;
            }else{
                l  = mid + 1;
            }
        }
        return l;
    }
  

    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        
        // int x = n*(n+1)/2;
        
        // int sum = 0;
        
        // for(int i=0; i<n; i++){
        //     sum += nums[i];
        // }
        
        // return x - sum;

//by binary search
        return solve(nums);
    }
};