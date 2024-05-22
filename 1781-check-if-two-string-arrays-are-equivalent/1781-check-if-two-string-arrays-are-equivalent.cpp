class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string s1 = "";
       string s2 = "";

       for(auto & s: word1){
        for(int i = 0; i<s.length(); i++){
        s1 += s[i];
        }
       } 

        for(auto & s: word2){
        for(int i = 0; i<s.length(); i++){
        s2 += s[i];
        }
       } 

       if(s1 == s2) return true;

       return false;
    }
};