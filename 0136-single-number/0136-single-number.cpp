class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // unordered_map<int, int> mp;

        // for(auto num: nums){
        //    mp[num]++;
        // }
        
        // int ans;
        // for(auto & it: mp){
        //     if(it.second == 1){
        //          ans = it.first;
        //     }
        // }
        // return ans;

        int ans = 0;
        for(auto & num: nums){
            ans^=num;
        }
        return ans;
    }
};
// USING BITWISE XOR OPERATOR (USING CONSTANT SPACE )
//A^A=0
//A^B^A=B
//here we, don't need to use unordered_map and sorting
