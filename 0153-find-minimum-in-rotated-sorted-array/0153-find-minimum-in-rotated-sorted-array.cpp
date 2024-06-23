// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//      // int i=0;
//      //    int j=nums.size()-1;
//      //    while(i<j){
//      //        int mid = (i+j)/2;
//      //        if(nums[mid] > nums[j]) i = mid+1;
//      //        else j=mid;
//      //    }
//      //    return nums[i];
//        int n= nums.size(); 
//         int low =0, high = n-1;
//         int ans =  INT_MAX;
//         while(low<=high){
//             int mid=(low+high)/2;
            
//             if(nums[low]<=nums[high]){
//                 ans = min(ans, nums[low]);
//                 break;
//             }
//             if(nums[low]<=nums[mid]){
//                 ans = min(ans, nums[low]);
//                 low++;
//             }
//             else{
//                 high = mid -1;
//                 ans = min(ans, nums[mid]);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n  = nums.size();

        int l  =0;
        int r = n -1;

        while(l < r){
            int mid =  l +  (r -l)/2;

            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }  

        return nums[r];
         }
};