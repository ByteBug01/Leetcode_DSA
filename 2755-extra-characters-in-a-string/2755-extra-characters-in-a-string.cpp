// class Solution {
// public:
//     map<string,int>m;
//     int c(int i,string &s,vector<int>&dp){
//         if(i>=s.size())return 0;
//         int ans=INT_MAX;
//         if(dp[i]!=-1)return dp[i];
//         ans = 1 + c(i+1,s,dp);
//         string k="";
//         for(int j=i;j<s.size();j++){
//             k+= s[j];
//             if(m[k]){
//                 ans=min(ans,c(j+1,s,dp));
//             }
//         }
//         return dp[i]=ans;
//     }
//     int minExtraChar(string s, vector<string>& d) {
//         for(auto i : d)m[i]++;
//         vector<int>dp(s.size(),-1);
//         return c(0,s,dp);
//     }
// };



class Solution {
public:
int n;
int solve(int i , unordered_set<string> &st, string s, vector<int> &dp){
    if(i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = 1 + solve(i+1, st, s, dp);

    for(int j =i; j<n; j++){
        string k = s.substr(i, j-i+1);
        if(st.count(k)){
             ans = min(ans, solve(j+1, st, s, dp));
        }
    } 
    return dp[i] = ans;
}

int minExtraChar(string s, vector<string>& d) {
    n = s.size();
    vector<int> dp(n, -1);

    unordered_set<string> st;

    for(string& ss: d){
        st.insert(ss);
    }

    return solve(0, st, s, dp);
}
};