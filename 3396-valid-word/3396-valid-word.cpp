class Solution {
public:
    bool isValid(string word) {
if(word.length() < 3)  return false;

bool hasVowel = false;
bool hasConsonant = false;

       for(char c: word){
        if(! isalnum(c)){
            return false;
        }

        c = tolower(c);

        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c  == 'u'){
            hasVowel = true;
        }

        if( isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c  == 'u')){
            hasConsonant = true;
        }
       }

       return hasVowel &&   hasConsonant;
    }
};