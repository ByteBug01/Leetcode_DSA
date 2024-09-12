class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
      set<char> st(allowed.begin(), allowed.end());

         
        int  ans = 0;
        for(auto& it: words){
            bool k = true;
            for(char ch: it){
                if(st.find(ch) == st.end()){
                    k= false;
                    break;
                }
            }
            if(k){
                ans++;
            }
        }

        return ans;
    }
};