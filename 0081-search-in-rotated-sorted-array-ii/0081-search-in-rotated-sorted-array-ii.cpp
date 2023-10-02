class Solution {
public:
    bool search(vector<int>& nums, int k) {
        // int i=0,j=v.size()-1;
        // while(i<=j){
        //     int m = (i+j)/2;
        //     if(v[m]==target)return true;
        //     if(v[i]==v[m] && v[m]==v[j]){
        //         i++;
        //         j--;
        //         continue;
        //     }
        //     if(v[m]>=v[i]){
        //         if(v[i]<= target && target<=v[m])j=m-1;
        //         else i = m+1;
        //     }
        //     else {
        //          if(v[j]>= target && target >= v[m])i=m+1;
        //         else j = m-1;
        //     }
        // }
        // return false;
        int n = nums.size();
        int low = 0, high=n-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==k) return true;
            
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
                if(nums[low]<= nums[mid])
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
        return false;
        }
        
    
};