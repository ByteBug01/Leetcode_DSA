class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> mp;

        for(auto& it: arr){
            mp[it]++;
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(mp[arr[i]] == 1){
                cnt++;
            }

            if(cnt == k){
                return arr[i];
            }
        }

        return "";
    }
};