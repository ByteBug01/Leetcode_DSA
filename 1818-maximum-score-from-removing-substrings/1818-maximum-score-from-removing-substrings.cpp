class Solution {
public:

int solve(string & s, string target, int score){
    stack<char> st;

    int totScore = 0;

    for(char& ch : s){
        if(st.size() == 0){
            st.push(ch);
        }else{
            if(st.top() == target[0] && ch == target[1]){
                st.pop();
                totScore += score;
            }else{
                st.push(ch);
            }
        }
    }

    s = "";

    while(!st.empty()){
        s += st.top();
        st.pop();
    }

    reverse(s.begin(), s.end());

    return totScore;
}

    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if(y>x) 
        {
            swap(s1, s2);
            swap(x, y);
        }

        return solve(s, s1, x) + solve(s, s2, y);
    }
};