class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        map<int, int> mp;
        
        for(int i =0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto m: mp){
            if(m.second>0.25*n){
                return m.first;
            }
        }
        return -1;
    }
};