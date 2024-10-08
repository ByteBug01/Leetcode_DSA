class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        stack<char> st;

        for(char ch: s){
            if(ch == '['){
                st.push(ch);
            }
           else if(!st.empty() && ch == ']' && st.top() == '['){
                st.pop();
            }
        }

        return (st.size() + 1)/2;
    }
};