// class Solution {
// public:
//     string reverseWords(string s) {
//     //     int n = s.size();

//     //     stack<char> st;

//     //     for(auto ch: s){
//     //         st.push(ch);
//     //     }

//     //    string ans = "";

//     //     while(!st.empty()){
//     //        string temp = "";
//     //        temp += st.top();
//     //        st.pop();
//     //        if(st.top() == ' '){
//     //         reverse(temp.begin(), temp.end());
//     //         ans = temp + " ";
//     //         temp = "";
//     //        } 
//     //     }

//     //     return ans;

//         //instead of pushing a character into stack push whole one word

//         int n = s.size();
//         stack<string> st;
//         string temp = "";
        
//         for(int i = 0; i < n; ++i) {
//             if(s[i] == ' ') {
//                 if(!temp.empty()) {
//                     st.push(temp);
//                     temp = "";
//                 }
//             } else {
//                 temp += s[i];
//             }
//         }
        
        
//         if(!temp.empty()) {
//             st.push(temp);
//         }

//         string ans = "";
        
    
//         while(!st.empty()) {
//             ans += st.top();
//             st.pop();
//             if(!st.empty()) {
//                 ans += " ";
//             }
//         }
        
//         return ans;
        

//     }
// };


class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        string word = "";
        for(char &ch: s){
           if(ch == ' '){
            if(!word.empty())
             { st.push(word);
              word = "";
              }
           }
           else word += ch;
        }

        if(!word.empty()) st.push(word);

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();

            if(!st.empty()){
                ans += " ";
            }

        }

        return ans;
    }};
