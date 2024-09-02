class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

       long long tot = 0;
        for(int it : chalk){
            tot+= it;
        }

        k = k%tot;

        for(int i = 0; i<n; i++){
            if(k < chalk[i]){
                return i;
            }
            k-=chalk[i];
        }
  return -1;
    }
};