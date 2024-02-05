class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
    
        unordered_map<int , int> mp;
        for(char c: s){
            mp[c]++;
        }
        
        for(int i=0; i<n; i++){
            if(mp[s[i]]==1){
          return i;
        }
        }
            
            return -1;
    }
};