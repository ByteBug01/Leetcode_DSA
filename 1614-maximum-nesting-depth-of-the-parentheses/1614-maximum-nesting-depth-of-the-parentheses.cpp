class Solution {
public:
    int maxDepth(string s) {
        
        int n  = s.length();
        
       int  d = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(') {
                cnt++;
                d = max(d, cnt);
            } 
            if(s[i] == ')'){
                cnt--;
                d = max(d, cnt);
            }
            
        }
        
        return d;
    }
};