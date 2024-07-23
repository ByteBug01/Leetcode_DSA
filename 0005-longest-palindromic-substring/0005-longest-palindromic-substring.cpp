// class Solution {
// public:

// int t[1001][1001];

//     bool solve(string & s, int i, int j){
        
//         if(t[i][j] != -1) return t[i][j];

//         if(i>=j){
//             return t[i][j] = 1;
//         }
        
//         if(s[i] == s[j])
//             return t[i][j] = solve (s, i+1, j-1);
        
//         return t[i][j] = 0;
//     }
    
//     string longestPalindrome(string s) {
//         int n = s.length();

//         memset(t, -1, sizeof(t));
        
//         int maxLen = INT_MIN;
//         int sp = 0;
        
//         for(int i = 0; i<n; i++){
//             for(int j = i; j<n; j++){
//                 if(solve(s,i,j) == true){
//                     if(j - i + 1 > maxLen){
//                         maxLen = j-i+1;
//                         sp = i;
//                     }
//                 }
//             }
//         }
//         return s.substr(sp, maxLen);
//     }
// };

class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n));

        int maxLen = 0;
        int sp = 0;

        maxLen = 1;
        for(int i = 0; i<n; i++){
            t[i][i] = true;
        }

        for(int len = 2; len<=n; len++){
            for(int i = 0; i<n-len+1; i++){

                int j = i+len-1;

                if(s[i] == s[j] && len == 2){
                    t[i][j] = true;
                    maxLen = 2;
                    sp = i;
                }else if(s[i] == s[j] && t[i+1][j-1] == true){
                    t[i][j] = true;

                    if(j-i+1> maxLen){
                        maxLen = j-i+1;
                        sp =  i;
                    }
                }else{
                    t[i][j] = false;
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};

