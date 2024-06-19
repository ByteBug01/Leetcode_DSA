class Solution {
public:
// nice stack problem
    int calculate(string s) {
        stack<int> st;

        int num = 0;
        int result  = 0;
        int sign = 1;

        for(char & c: s){
            if(isdigit(c)){
                 num = num*10 + (c - '0');
            }else if(c == '+'){
                 result += (num*sign);
                 num = 0;
                 sign = 1;
            }else if(c == '-'){
                result += (num*sign);
                 num = 0;
                 sign = -1;
            }else if(c == '('){
                 st.push(result);
                 st.push(sign);
                 result = 0;
                 num = 0;
                 sign  =1;
            }else if(c == ')'){
                 result += (num * sign); //bracket k ander ka result compute krega idhr
                 num = 0;

                 result *= st.top(); //stack k top pe sign h
                 st.pop();
                 result += st.top(); // stack m sign k niche braket k bhar ka result stored hai
                 st.pop();
            }
        }
        result += (sign* num);
        return result;
    }
};