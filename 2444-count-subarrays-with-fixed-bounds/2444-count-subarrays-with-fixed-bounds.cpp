class Solution {
public:
    
    //crux for this problem
    // smaller = min(minK_idx, maxK_index)
    // culprit_idx //(index is not in the range of mink, maxK)
    // temp = smaller - culprit_idx
    // ans += (temp <= 0)? 0 : temp
    
    
    typedef long long ll;
    
//     ll findMin(vector<ll> & subarr){
//         ll n = subarr.size();
        
//         ll mini =  INT_MAX;
        
//         for(ll i = 0; i<n; i++){
//             mini = min(mini, subarr[i]);
//         }
        
//         return mini;
//     }
    
//     ll findMax(vector<ll> & subarr){
//         ll n = subarr.size();
        
//         ll maxi =  INT_MIN;
        
//         for(ll i = 0; i<n; i++){
//             maxi = max(maxi, subarr[i]);
//         }
        
//         return maxi;
//     }
    
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//          ll n  = nums.size();
        
//         vector<ll> subarr;
        
//         int cnt = 0;
        
//         for(ll i = 0; i<n; i++){
//             for(ll j = i; j<n; j++){
//                 for(ll k = i; k<= j; k++){
//                     subarr.push_back(nums[k]);
//                 }
                
//                 int mi = findMin(subarr);
//                 int ma = findMax(subarr);
                
//                 if(mi == minK && ma == maxK){
//                     cnt++;
//                 }
                
//                 subarr.clear();
//             }
//         }
        
//         return cnt;
//     }
//     
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        ll n = nums.size();
        
        ll ans = 0;
         
        int minK_idx = -1;
        int maxK_idx = -1;
        int culprit_idx = -1;
        
        for(int i  = 0 ; i<n; i++){
            
            if(nums[i] < minK || nums[i] > maxK){
                culprit_idx = i;
            }
            if(nums[i] == minK){
                minK_idx = i;
            }
            if(nums[i] == maxK){
                maxK_idx = i;
            }
            
           ll smaller = min(minK_idx,  maxK_idx);
            
            ll temp = smaller - culprit_idx;
            
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};



