// class Solution {
// public:
    
    
//     int search(vector<int>& nums, int k) {
// //         int n = nums.size();
// //         int left= 0;
// //         int right = n-1;
// //         int mid;
        
// //         while(left<=right){
// //             mid = (left+right)/2;
// //             if(nums[mid]==target)
// //                 return mid;
// //             else if(nums[mid]>=nums[left]){
// //                 if(target<=nums[mid] && target>=nums[left])
// //                     right = mid-1;
// //                 else
// //                     left = mid+1;
// //             }
// //             else
// //             {
// //                 if(target>=nums[mid] && target<=nums[right])
// //                     left = mid+1;
// //                 else
// //                     right = mid-1;
// //             }
// //         }
// //         return -1;
        
//         int n = nums.size();
//         int low =0, high = n-1;
//         while(low<=high)
//         {
//           int  mid=(low+high)/2;
//             if(nums[mid]==k) return mid;
//             else if(nums[low]<= nums[mid])
//             {
//                  if(nums[low]<= k && nums[mid]>=k)
//                  {
//                      high = mid-1;
//                  }else
//                  {
//                      low=mid+1;
//                  }
//             }
            
//             else
//             {
//                 if(nums[mid]<= k && nums[high]>= k)
//                 {
//                     low = mid+1;
//                 }else
//                 {
//                     high=mid-1;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:

int find_pivot(vector<int>& nums, int n){
    int l = 0; int r = n-1;

    while(l < r){
        int mid = l + (r - l)/2;

        if(nums[mid] > nums[r]){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    return r;
}

int binary_search(int l, int r, vector<int> & nums, int k){
  int idx  =-1;
    while(l <= r){
        int mid = l + (r- l)/2;
        
        if(nums[mid] == k) 
        {idx = mid; break;}
       else if(nums[mid] < k){
        l = mid+1;
       }else{
        r = mid -1;
       }
    }
return idx;
}

    int search(vector<int>& nums, int k) {
        int n = nums.size();

        int pivot_idx = find_pivot(nums, n);

        int idx = binary_search(0, pivot_idx-1, nums, k);

        if(idx != -1){
            return idx;
        }

        idx = binary_search(pivot_idx, n-1, nums, k);

        return idx;
    }
};