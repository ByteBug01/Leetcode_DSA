class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        
        string s1 = "";
        string s2 = "";
        
        for(int  i = 0; i<n; i++){
            if(i<n/2){
                s1 += s[i];
            }else{
                s2 += s[i];
            }
        }
        
        int cnt1 = 0, cnt2 = 0;
        
        for(int i = 0; i<n/2; i++){
            
            s1[i] = tolower(s1[i]);
            s2[i] = tolower(s2[i]);
            
            if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o'|| s1[i] == 'u' ){
                cnt1++;
            }
            
            if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o'|| s2[i] == 'u' ){
                cnt2++;
            }
        }
        
        return cnt1 == cnt2;
    }
};