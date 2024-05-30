class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> prefixXor(n+1, 0);
        //prefixXor[0] = 0;

        for(int i = 1; i<=n; i++){
             // prefixXor[i] = arr[i-1];
               prefixXor[i] = prefixXor[i-1] ^ arr[i-1] ;
        }

        int cnt = 0;

         for(int i = 0; i<prefixXor.size(); i++){
            for(int k = i+1; k<prefixXor.size(); k++){
                if(prefixXor[i] == prefixXor[k]){
                    cnt += (k - i - 1);
                }
            }
         }
        return cnt;
    }
};