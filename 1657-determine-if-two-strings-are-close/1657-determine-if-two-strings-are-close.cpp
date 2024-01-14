class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int m = w1.length();
        int n = w2.length();
        
        if(m!=n) return false;
        
        vector<int> f1(26);
        vector<int> f2(26);
        
        for(int i = 0; i<m; i++){
            f1[w1[i] - 'a']++;
            f2[w2[i] - 'a']++;
        }
        
        for(int i =0; i<26; i++){
            if(f1[i] != 0 && f2[i] != 0) continue;
            
             if(f1[i] == 0 && f2[i] == 0) continue;
            
            return false;
        }
        
        sort(begin(f1), end(f1));
        sort(begin(f2), end(f2));
        
        
        return f1 == f2;
    }
};