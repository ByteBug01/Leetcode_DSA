class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);
        int n  =  numstr.size();

        int maxnum = num;

        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(numstr[i], numstr[j]);

                maxnum = max(maxnum, stoi(numstr));

                swap(numstr[i], numstr[j]);
            }
        }

    return maxnum;
    }
};