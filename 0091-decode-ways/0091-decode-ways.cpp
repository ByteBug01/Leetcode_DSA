// class Solution {
// public:
//     int t[101];
    
//     int solve(int i, string &s, int &n){
//         if(t[i] != -1){
//             return t[i];
//         }
        
//         if(i==n){
//             return t[i] = 1;
//         }
        
//         if(s[i] == '0'){
//             return t[i] = 0;
//         }
        
//         int result = solve(i+1, s, n);
        
//         if(i+1 < n){
//         if(s[i] == '1'  || (s[i]== '2' && s[i+1] <= '6'))
//             result += solve(i+2, s, n);
//         }
//         return t[i] = result;
//     }
    
    
    
//     int numDecodings(string s) {
//     //     int n = s.size();
//     // if (n == 0)
//     //   return 0;
//     // vector<int> dp(n + 1, 0);
//     // dp[0] = 1;
//     // dp[1] = s[0] == '0' ? 0 : 1;
//     // for (int i = 2; i <= n; i++)
//     // {
//     //   int first = stoi(s.substr(i - 1, 1));
//     //   int second = stoi(s.substr(i - 2, 2));
//     //   if (first >= 1 && first <= 9)
//     //     dp[i] += dp[i - 1];
//     //   if (second >= 10 && second <= 26)
//     //     dp[i] += dp[i - 2];
//     // }
//     // return dp[n]; 
        
//         memset(t, -1, sizeof(t));
        
//         int n = s.length();
        
//         return solve(0,s,n);
        
//     }
// };

//--------------bottom-up------------------
class Solution {
public:

  int numDecodings(string s) {
    int n = s.length();

    vector<int> t(n+1, 0);
    t[n] = 1;

    for(int i =n-1; i>=0; i--){
        if(s[i] == '0'){
            t[i] = 0;
        }else{

            t[i] = t[i+1];

            if(i+1 < n){
                if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                    t[i] += t[i+2];
                }
            }
        }
    }


    return t[0]; //0th idx m sare ways store honge
  }
};
