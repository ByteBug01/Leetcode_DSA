class Solution {
public:
//subset bola h, subarray nai,....

void dfs(int i, int currOR, int maxbitOR, int & cnt, vector<int>& nums){
    if(i == n){
        if(currOR == maxbitOR){
            cnt++;
        }
        return;
    }

    dfs(i+1, currOR|nums[i], maxbitOR, cnt, nums);//take curr ele of nums

    dfs(i+1, currOR, maxbitOR, cnt, nums); //not take
}

int n;

    int countMaxOrSubsets(vector<int>& nums) {
        int maxbitOR = 0;
        n = nums.size();

       for(auto& it: nums){
          maxbitOR |= it;
       }

       int cnt = 0;

       dfs(0, 0, maxbitOR, cnt, nums);

       return cnt;
    }
};