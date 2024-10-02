class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        vector<int> tmp(arr.begin(), arr.end());
        sort(tmp.begin(), tmp.end());
       
   int rank = 1;
   for(int i = 0; i<tmp.size(); i++){
     if(mp.find(tmp[i]) == mp.end()){
        mp[tmp[i]] = rank++;
     }
   }
  

vector<int> ans(arr.size());
for(int i = 0; i < arr.size(); ++i){
   ans[i] = mp[arr[i]];
}

return ans;
    }
};