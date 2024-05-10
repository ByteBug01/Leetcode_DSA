class Solution {
public:

// int solve(string & s, int i , int j ){
    
//    if(i > j) return 0;

//    if(i ==  j) return 1; //one character

//    if(s[i] == s[j]) {
//       return 2 + solve(s, i+1, j+1);
//    }else{
//     return max(solve(s, i+1, j), solve(s, i, j-1));
//    }

// }


//LCS se ban jaega (longest common subsequence)


int t[1001][1001];

int LCS(string &s1, string& s2, int m, int n){
   if(m == 0 || n==0){
    return t[m][n] = 0;
   }

   if(t[m][n] != -1){
    return t[m][n];
   }

   if(s1[m-1] == s2[n-1]){
    return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
   }

    return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
   
}


    int longestPalindromeSubseq(string s) {
        // int i = 0;
        // int j = s.size() -1;
        // int ans = solve(s, i, j);
        // return ans;
        memset(t, -1, sizeof(t));

        string s2 = s;
        reverse(s2.begin(), s2.end());

        int m = s.length();

        return LCS(s, s2, m, m);

    }
};