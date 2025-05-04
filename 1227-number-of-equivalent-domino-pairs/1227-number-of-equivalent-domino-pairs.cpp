class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        //think all possible way to solve the  prblm
        vector<int> cnt(150);
        int ans = 0;

        for(auto &it : dominoes){
            int num = (it[0]> it[1])?10*it[0]+it[1]: 10*it[1]+it[0];
            ans += cnt[num];
            cnt[num]++;
        }

        return ans;
    }
};