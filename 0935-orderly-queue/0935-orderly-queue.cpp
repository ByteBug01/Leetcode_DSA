class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        for(int i =1; i<= n-1; i++){
            string temp = s.substr(i) + s.substr(0, i);
            ans = min(ans, temp);
        }

        return ans;
    }
};