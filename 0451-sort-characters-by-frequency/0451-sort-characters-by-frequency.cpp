class Solution {
public:
    string frequencySort(string s) {
//         unordered_map<char,int>mp;
//         for(int i=0;i<s.length();i++){
//             mp[s[i]]++;
//         }
//         s="";
//         vector<pair<char,int>>vec(mp.begin(), mp.end());

//     sort(vec.begin(), vec.end(), [](const pair<char,int>& a, const pair<char, int>& b) {
//         return a.second > b.second;
//     });
//         for(auto i:vec){
            
//             if(i.second>1){
//                 int count=0;
//                 while(count<i.second){
//                     s+=i.first;
//                     count++;
//                 }
//             }
//             else
//             s+=i.first;
//         }
//         return s;
        
        int n = s.length();
        
        unordered_map<char, int> mp;
        
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }
        
        string ans = "";
        
        vector<std::pair<char, int>> vec(mp.begin(), mp.end());


       sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; 
    });

        
        for(auto it: vec){
            int i = it.second ;
            while(i--){
                ans += it.first;
            }
        }
        
        return ans;
        
    }

};