class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        // map<int, int> m;
        // for(int i=0; i<n; i++){
        //     m[nums[i]]++;
        // }
        // int k;
        // for(auto it: m){
        //     if(it.second > n/2){
        //          k = it.first;
        //     }
        // }
        // return k;
        
        
        //.............Boyer-Moore Algorithm.................//
        
//         int cnt = 0;
//         int el;
        
//         for(int i = 0; i<n; i++){
//             if(cnt == 0){
//                 cnt = 1;
//                 el = nums[i];
//             }
            
//             else if(nums[i] == el){
//                 cnt++;
//             }
            
//             else{
//                 cnt--;
//             }
//         }
        
//         int cnt1 = 0;
//         for(int i =0; i<n ; i++){
//             if(nums[i] == el) cnt1++;
//         }
        
//       return el;
        
        int cnt  =0;
        int maj = NULL;
        
        for(int i = 0; i<n; i++){
            if(nums[i] == maj){
                cnt++;
            }
            else if(cnt ==  0){
                maj = nums[i];
                cnt  = 1;
            }else{
                cnt--;
            }
        }
        
        return maj;
        //.............................//
        // return -1;
    }
};