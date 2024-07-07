class Solution {
public:


void solve(int n,  vector<string>& ans, string curr ){

    if(curr.length() == n){
        ans.push_back(curr);
        return;
    }

    if(curr.empty() || curr.back() == '1'){
        solve(n, ans, curr + "1");
        solve(n, ans, curr + "0");
    }else{
         solve(n, ans, curr + "1");
    }
}
    vector<string> validStrings(int n) {
        vector<string> ans;

        solve(n, ans, "");

        return ans;
    }
};