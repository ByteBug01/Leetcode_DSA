class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for(auto c: s){
            if(c=='B' &&  st.size()>0 && st.top()=='A'){
                st.pop();
            }
           else if(c=='D' &&  st.size()>0 && st.top()=='C'){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.size();
    }
};