class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
      int sz=t.size();
        vector<int> trusts(n+1,0), trusted(n+1,0);
        for (int i=0; i<sz; i++) {
            trusts[t[i][0]]++;
            trusted[t[i][1]]++;
        }
        for (int i=1; i<=n; i++) {
            if (trusts[i]==0 && trusted[i]==n-1) return i;
        }
        return -1;
        
        
    }
};