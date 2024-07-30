// class Solution {
// public:
//     int minimumDeletions(string s) {
//         bool seen = false;
//         int n = s.length();
//         int cnt  = 0;
//         for(int i =n-1; i>=0; i--){
            
//             if(s[i] == 'a') seen = true;
//             else if(s[i] == 'b') seen = false;

//             if(s[i] == 'b' && seen == true){
//                 cnt++;
//                 seen = false;
//             }

//         }

// int cnt1  =0;
// bool seen2 =false;
//                 for(int i =0; i<n; i++){
            
//             if(s[i] == 'b') seen2 = true;
//             else if(s[i] == 'a') seen2 = false;

//             if(s[i] == 'a' && seen2 == true){
//                 cnt1++;
//                 seen2 = false;
//             }

//         }

//         return min(cnt1, cnt);
//     }
// };

//-----------------------------------------------------------------------
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.length();
//         int countB = 0;
//         int minDel = 0;
        
//         for (char c : s) {
//             if (c == 'b') {
//                 countB++;
//             } else {
//                 minDel = min(minDel + 1, countB);
//             }
//         }
        
//         return minDel;
//     }
// };

//approach - 1:--------------------------------------
// class Solution {
// public:
//     int minimumDeletions(string s) {
            
//             stack<char> st;
//             int cnt = 0;
//             for(auto & ch: s){
//                 if(!st.empty() && st.top() == 'b' && ch == 'a'){ //cnt 'ba'
//                    st.pop();
//                     cnt++;
//                 }else{
//                     st.push(ch);
//                 }
//             }

//             return cnt;
//     }
// };


//approach-2:--------------------------------------------------

class Solution {
 public:
    int minimumDeletions(string s) {

        int n = s.length();

        vector<int> left_b_cnt(n, 0);
        vector<int> right_a_cnt(n, 0);

int cnt_b = 0;
        for(int i= 0; i<n; i++){
            left_b_cnt[i] = cnt_b;

            if(s[i] == 'b'){
                cnt_b++;
            }
        }

        int cnt_a = 0;

        for(int i = n-1; i>=0; i--){
            right_a_cnt[i] = cnt_a;

            if(s[i] == 'a'){
                cnt_a++;
            }
        }

int minCnt = INT_MAX;
        for(int i = 0; i<n; i++){
             minCnt = min(minCnt, left_b_cnt[i]+right_a_cnt[i]);
        }


        return minCnt;
    }
};