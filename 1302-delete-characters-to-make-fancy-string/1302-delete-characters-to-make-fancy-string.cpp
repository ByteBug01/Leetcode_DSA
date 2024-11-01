class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();

        string ans = "";
        int cnt = 1;

        for(int i = 0; i<n; i++){
          
            if(i == 0 || s[i] != s[i-1]){
                cnt = 1;
            }else{
                cnt++;
            }

            if(cnt < 3){
                ans += s[i];
            }
        }

        return ans;
    }
};