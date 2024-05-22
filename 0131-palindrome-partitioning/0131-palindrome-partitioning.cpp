class Solution {
public:
//using backtracking--------------------------------------------------------------
bool  Palindrome(string s, int i, int j){
while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
}

void backtrack(string & s, int start, vector<string>&path, vector<vector<string>>&ans ){
     if (start == s.length()) {
            ans.push_back(path);
            return;
        }

        for (int end = start + 1; end <= s.length(); ++end) {
          
            if (Palindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                backtrack(s, end, path, ans);
                path.pop_back();
            }
        }
}


    vector<vector<string>> partition(string s) {
         vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
};