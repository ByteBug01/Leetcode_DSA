class Solution {
public:
    //space : O(1)
    //time :  o(n)
    string minRemoveToMakeValid(string s) {
        int n  = s.size();
        //for extra closing bracket
        int cnt  = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else if(s[i] == ')'){
                if(cnt == 0){
                    s[i] = '*';
                }
                else{
                    cnt--;
                }
            }
        }
        
        //for extra opening bracket
         cnt  = 0;
        
        for(int i = n-1; i>= 0; i--){
            if(s[i] == ')'){
                cnt++;
            }
            else if(s[i] == '('){
                if(cnt == 0){
                    s[i] = '*';
                }
                else{
                    cnt--;
                }
            }
        }
        
        string ans = "";
        
        for(int  i = 0; i<n ; i++){
            if(s[i] != '*'){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};