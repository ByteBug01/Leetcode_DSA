class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//          map<int, int> m;
//         int dup=0;
//         for(int i=0; i<nums.size(); i++){
//             m[nums[i]]++;

//         }

//         for(auto i: m){
//             if(i.second>1){
//                 dup=i.first;
//                 break;
//             }
//         }
//         return dup;
        
         int tortoise = nums[0];
        int hare = nums[0];

        // Phase 1: Detecting the intersection point of the two pointers
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Phase 2: Finding the entrance to the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};