class Solution {
public:
//USING BIT MANIPULATION
    char findTheDifference(string s, string t) {
        int ans = 0;

        for(char & ch : s){
            ans += ch;
        }
        for(char & ch : t){
            ans -= ch;
        }
        return char(abs(ans));

    }
};