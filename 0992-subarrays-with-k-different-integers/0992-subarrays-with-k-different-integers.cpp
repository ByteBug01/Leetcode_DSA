class Solution {
public:
   
    
//     vector<int>  SubArrays(vector<int> & nums, int i , int j){
//         if(j == n){
//             return ;
//         }
        
//         else if(i>j){
//             SubArrays(nums, 0, j+1);
//         }
//         else{
//         for(int i = 0; i<j; i++){
//            return SubArrays(nums, i+1, j );
//         }
//         }  
//     } //bkwass
    
    
    int slideWindow(vector<int> & nums, int k){
        int n = nums.size();
        
        unordered_map<int , int> mp;
        
        int  i = 0; int j = 0;
        int cnt = 0 ;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                   i++;
            }
                   cnt += (j - i +1); //cnt of subarrays ending at j
            j++; // don't forget
        }
                   
                   return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return slideWindow(nums, k) - slideWindow(nums, k-1);
    }
};