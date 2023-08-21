class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        string c = t.substr(1,t.size()-2);
        if(c.find(s) != -1){
            return true;
        }
        return false;
    }
};