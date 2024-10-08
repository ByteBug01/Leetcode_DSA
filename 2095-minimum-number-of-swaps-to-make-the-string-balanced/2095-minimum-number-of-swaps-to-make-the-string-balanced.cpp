//approach - 1
// class Solution {
// public:
//     int minSwaps(string s) {
//         int n = s.length();
//         stack<char> st;

//         for(char ch: s){
//             if(ch == '['){
//                 st.push(ch);
//             }
//            else if(!st.empty() && ch == ']' && st.top() == '['){
//                 st.pop();
//             }
//         }

//         return (st.size() + 1)/2;
//     }
// };

//approach - 2
class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0;

        for (char ch : s) {
            if (ch == '[') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    close++;
                }
            }
        }

        return (close + 1) / 2;
    }
};
