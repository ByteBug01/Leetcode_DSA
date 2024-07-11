class Solution {
public:

// ( ish bracket ke phle wala chars skip krna hai
    string reverseParentheses(string s) {
        stack<int> skip;

        string ans = "";

        for(auto& ch : s){
            if(ch == '('){
                skip.push(ans.length());
            }else if(ch == ')'){
               int l = skip.top();
               skip.pop();
               reverse(ans.begin() + l, ans.end());
            }else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};