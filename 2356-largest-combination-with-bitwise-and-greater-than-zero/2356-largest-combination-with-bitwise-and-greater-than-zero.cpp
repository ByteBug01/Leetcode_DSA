class Solution {
public:
    int largestCombination(vector<int>& candidates) {
    //  as to have AND of ele to be greater than 0, you should have atleast one common
    // position at which it is 1 bit

    // therefore, count the 1 bit at every pos of every ele

    vector<int> bitcnt(24, 0);

for(int i=0; i<24; i++)
    {for(auto num: candidates){
        if((num & (1 << i))!= 0){          //bracket is imp
            bitcnt[i]++;
        }
    }}

return *max_element(bitcnt.begin(), bitcnt.end());

    }
};