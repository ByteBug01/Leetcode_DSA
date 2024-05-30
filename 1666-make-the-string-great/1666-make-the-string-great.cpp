// class Solution {
// public:
    
//     string func(string s, int i, map<char, char> lowerToUp){
//        int n = s.size();
        
//         if(i >= n-1){
//             return s;
//         }
   
//             if(s[i] == lowerToUp[s[i+1]] || lowerToUp[s[i]] == s[i+1]){
//                 s.erase(i, 2);
                
//                 if(i>0){     //don't forget this condition
//                     i--;
//                 }
                
//                 return func(s, i, lowerToUp); //remember
//             }
        
//        return func(s, i+1, lowerToUp);  //remember
            
       
//     }
    
//     string makeGood(string s) {
//          map<char, char> lowerToUp;
        
//     for (char c = 'a'; c <= 'z'; ++c) {
//         lowerToUp[c] = toupper(c);
//     }
        
//         int i  =0;
//       string str = func(s, i, lowerToUp);
        
//         return str;
        
//     }
// };
//-------------------------------------------------------------------------------
class Solution {
public:
 string makeGood(string s) {
  string result = "";
        
        for(char &ch : s) {
            if(result.size() > 0 && (ch + 32 == result.back() || ch - 32 == result.back())) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        
        return result;
 }
};