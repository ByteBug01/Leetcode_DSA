class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.length() < k){
            
             string g = "";
           for(char& ch: s){
      
            if(ch == 'z') g += 'a';
            else    g += ch+1; 
             
           }
        s += g;
        }


        
        return s[k-1];
    }
};