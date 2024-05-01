class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.size();
        
        string s1 = "";
        string s2  = "";
        
        bool t = false;
        
        int i = 0;
    
             // if(word[i] == ch){
             //     s1 += word[i];
             //     t =  true;
             // }
            
//             if(word[i] == ch){
//                 t = true;
//             }
            
//             while(word[i] != ch){
//                 if(i == n){
//                     break;
//                 }
//                 else{
                    
//                     s1 += word[i];
//                     i++;
//                     t = true;
//                     if(word[i] == ch){
//                         break;
//                     }
//                 }
//             }
            
        int c =0;
        for(int i = 0; i<n; i++){
            if(word[i] == ch){
                // s1 += word[i];
                t  = true;
                break;
            }else{
                s1 += word[i];
                c++;
            }
        }
        
        
        string ans = "";
        
        if(t){
            s1 += ch;
            
        reverse(s1.begin(), s1.end());
            for(int j = c+1; j<n; j++){
                s2 += word[j];
            }
            
            ans = s1 + s2;
            return ans;
        }else{
            return word;
        }
        
    }
};