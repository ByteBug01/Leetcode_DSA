class Solution {
public:
    //"(1+(2*3)+((8)/4))+1"
  // 0 1  2   1 23 2  1 0
    
    //already given string as VPS
    
    //TC : O(n)
    //SC : O(1)
    
//     int maxDepth(string s) {
        
//         int n  = s.length();
        
//        int  d = 0;
//         int cnt = 0;
//         for(int i = 0; i<n; i++){
//             if(s[i] == '(') {
//                 cnt++;
//                 d = max(d, cnt);
//             } 
//             if(s[i] == ')'){
//                 cnt--;
//                 d = max(d, cnt);
//             }
            
//         }
        
//         return d;
//     }
    
    //--------------------------------//
    // TC = O(n)
    //SC = O(n)
    
    int maxDepth(string s) {
        int ans = 0 ;
        stack<char> st;
        
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }else if(ch == ')'){
                st.pop();
            }
            
            ans = max(ans, (int)st.size());
        }
        
        
        return ans;
    }
};