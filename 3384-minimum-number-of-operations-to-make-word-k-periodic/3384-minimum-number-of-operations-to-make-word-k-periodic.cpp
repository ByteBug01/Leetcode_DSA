class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        // seems to be hard but easy
        // use hashmaps

        int n  = word.size();
        unordered_map<string, int> mp;
     int   maxi = 0;

        for(int i  =0; i<n; i+=k){
            string s = word.substr(i, k);
            mp[s]++;

            maxi = max(maxi, mp[s]);
        }

        return (n/k - maxi);
    }
};