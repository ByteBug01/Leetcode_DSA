class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        string ans = "";

        for(int i=n-1;  i>=0; i--){
            int d = num[i] - '0';

            if(d%2 != 0) {
                ans = num.substr(0, i+1);
                return ans;
                }

        }

return "";
    }
};