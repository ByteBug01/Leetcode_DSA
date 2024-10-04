class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n  =skill.size();

  //      int currsum = 0;
        int targetsum = skill[0] + skill[n-1];
        long long totchem = 0;

        for(int i = 0; i<n/2; i++){
         int   currsum = skill[i] + skill[n-i-1];

            if(currsum != targetsum) return -1;

            totchem += (long long)skill[i] * (long long)skill[n-i-1];
        }

        return totchem;
    }
};