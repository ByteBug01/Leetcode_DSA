class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        int n = words.size();
        
        for(int i = 0; i<n; i++){
             string temp = string(words[i].rbegin(), words[i].rend()); 
            if(words[i] == temp){
                return words[i];
            }
        }
      return "";
    }
};