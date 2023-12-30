class Solution {
public:
    bool makeEqual(vector<string>& words) {
        string s;
        int n = words.size();
        
        if(n == 1){
            return true;
        }
        
        for(int i = 0; i<words.size(); i++){
            s += words[i];
        }
        
        
        unordered_map<char, int> mp;
        
        for(char ch: s){
            mp[ch]++;
        }
        
        for(auto m: mp){
            if(m.second % n != 0){
                return false;
            }
        }
        
        return true;
    }
};