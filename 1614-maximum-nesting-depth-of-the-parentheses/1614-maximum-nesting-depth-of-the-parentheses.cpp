class Solution {
public:
    //"(1+(2*3)+((8)/4))+1"
  // 0 1  2   1 23 2  1 0
    
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