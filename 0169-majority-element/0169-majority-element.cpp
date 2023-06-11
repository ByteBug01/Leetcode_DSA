class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int k;
        for(auto it: m){
            if(it.second > n/2){
                 k = it.first;
            }
        }
        return k;
    }
};