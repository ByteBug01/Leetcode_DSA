class Solution {
public:
//very easy problm
//just do, sort if k > 1
//else if k == 1, apply bruteforce 

    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        int n = s.length();
        for(int i = 0; i<=n-1; i++){
            string tmp = s.substr(i) + s.substr(0, i);
            ans = min(ans, tmp);
        }

        return ans;
    }
};