class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        
        int mpS[26] = {0};
        int mpT[26] = {0};
        
        for(int i = 0; i<n; i++){
            mpS[s[i]- 'a']++;  //character index no. will be increament to its frequency
            mpT[t[i]- 'a']++;
        }
        
        int ans = 0 ;
        
        for(int  i =0; i<26; i++){
            if(mpS[i]  > mpT[i]){
                ans += mpS[i] - mpT[i];
            }
        }
        
        return ans;
    }
};