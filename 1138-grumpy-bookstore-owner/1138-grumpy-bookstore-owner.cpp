class Solution {
public:
//sliding window------------------------------------------------------
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();

        int maxUnsat = 0;
        int currUnsat = 0;

        for(int i =0; i<minutes; i++){
           currUnsat += customers[i] * grumpy[i];
        }

        int i  =0;
        int j= minutes;
        maxUnsat = currUnsat;
        while(j<n){
            currUnsat += customers[j] * grumpy[j];
            currUnsat -= customers[i] * grumpy[i];
            maxUnsat = max(maxUnsat, currUnsat);
            i++;
            j++;
        }

        int totunsat = maxUnsat;

        for(int i =0; i<n; i++){
            if(grumpy[i] == 0){
                totunsat += customers[i];
            }
        }
return totunsat;
    }
};