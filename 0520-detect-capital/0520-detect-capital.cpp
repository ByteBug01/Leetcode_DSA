class Solution {
public:
    bool detectCapitalUse(string word) {
       int cnt = 0;

       for(char& ch: word){
        if(isupper(ch)){
            cnt++;
        }
       } 

       if(cnt == 0) return true;

       if(cnt == word.length()) return true;

       if(cnt == 1 && isupper(word[0])) return true;


       return false;
    }
};