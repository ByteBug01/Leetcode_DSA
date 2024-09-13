class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for(auto & it: queries){
            int a = it[0];
            int b = it[1];
            int tmp = 0;
            for(int i = a; i <= b; i++){
                tmp ^= arr[i];  
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
