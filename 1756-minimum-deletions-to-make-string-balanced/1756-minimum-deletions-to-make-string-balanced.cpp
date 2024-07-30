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


class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int countB = 0;
        int minDel = 0;
        
        for (char c : s) {
            if (c == 'b') {
                countB++;
            } else {
                minDel = min(minDel + 1, countB);
            }
        }
        
        return minDel;
    }
};
