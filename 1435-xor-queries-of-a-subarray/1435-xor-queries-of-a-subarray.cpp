class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // vector<int> ans;
        
        // for(auto & it: queries){
        //     int a = it[0];
        //     int b = it[1];
        //     int tmp = 0;
        //     for(int i = a; i <= b; i++){
        //         tmp ^= arr[i];  
        //     }
        //     ans.push_back(tmp);
        // }
        // return ans;

        vector<int> ans;
        int n = arr.size();
        vector<int> xorPrefix(n+1, 0);

        for(int i=0; i<n; i++){
           xorPrefix[i+1] = xorPrefix[i] ^ arr[i];
        }

        for(auto& it: queries){
            int a = it[0];
            int b = it[1];
            
            ans.push_back(xorPrefix[b+1] ^ xorPrefix[a]);
        }

        return ans;
    }
};
