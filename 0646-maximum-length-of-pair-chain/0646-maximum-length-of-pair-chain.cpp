// class Solution {
// public:
// //LIS Varient
// //memoization
// int t[1001][1001]; 

// int memoi(vector<vector<int>>& pairs,int p, int curr_idx ){

//    int n = pairs.size();

// if(curr_idx == n){
//     return 0;
// }

//    if(p != -1 && t[p][curr_idx] != -1){
//     return t[p][curr_idx];
//    }

// int take  = 0;
//    if(p == -1 || pairs[p][1] < pairs[curr_idx][0]){
//  take = 1 + memoi(pairs, curr_idx, curr_idx+1);
//    }

//    int not_take = memoi(pairs, p, curr_idx+1);

//    //this check is imp
// if(p != -1){
// t[p][curr_idx] = max(take, not_take);
// }

//    return max(take, not_take);
// }


//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n = pairs.size();

//         memset(t, -1, sizeof(t));

//         sort(pairs.begin(), pairs.end()); //must to sort

//       int prev_idx = -1;
//       int curr_idx = 0;

//         return memoi(pairs, prev_idx, curr_idx);
//     }
// };

//BOTTOM-UP-----------------------------------------------------------

class Solution {
public:

 int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        vector<int> t(n, 1);

        sort(pairs.begin(), pairs.end());

        int maxChainLen = 1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    t[i] = max(t[i], t[j] + 1);
                    maxChainLen = max(maxChainLen, t[i]);
                }
            }
        }
return maxChainLen;
 }
};