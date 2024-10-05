class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        int counter = 0;
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                if(counter>0){
                   ans += s[i]  ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                }
                counter++;
            }else{
                counter--;
                if(counter > 0){
                    ans += s[i] ;
                }
            }
        }


return ans;
   }
};