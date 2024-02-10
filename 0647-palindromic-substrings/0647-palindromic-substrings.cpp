class Solution {
public:
    
    bool isvalidpalin(string s){
        string P = s;
        reverse(P.begin(), P.end());
        return s == P;
    }
    
    
    
    int countSubstrings(string s) {
       int n = s.size();
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                string news = s.substr(i, j - i + 1);
                if(isvalidpalin(news)){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};