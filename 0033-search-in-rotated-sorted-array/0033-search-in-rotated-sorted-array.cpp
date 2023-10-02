class Solution {
public:
    
    
    int search(vector<int>& nums, int k) {
//         int n = nums.size();
//         int left= 0;
//         int right = n-1;
//         int mid;
        
//         while(left<=right){
//             mid = (left+right)/2;
//             if(nums[mid]==target)
//                 return mid;
//             else if(nums[mid]>=nums[left]){
//                 if(target<=nums[mid] && target>=nums[left])
//                     right = mid-1;
//                 else
//                     left = mid+1;
//             }
//             else
//             {
//                 if(target>=nums[mid] && target<=nums[right])
//                     left = mid+1;
//                 else
//                     right = mid-1;
//             }
//         }
//         return -1;
        
        int n = nums.size();
        int low =0, high = n-1;
        while(low<=high)
        {
          int  mid=(low+high)/2;
            if(nums[mid]==k) return mid;
            else if(nums[low]<= nums[mid])
            {
                 if(nums[low]<= k && nums[mid]>=k)
                 {
                     high = mid-1;
                 }else
                 {
                     low=mid+1;
                 }
            }
            
            else
            {
                if(nums[mid]<= k && nums[high]>= k)
                {
                    low = mid+1;
                }else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};