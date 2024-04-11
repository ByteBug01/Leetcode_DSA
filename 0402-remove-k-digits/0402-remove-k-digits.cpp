class Solution {
public:
    string removeKdigits(string num, int k) {
        
//         int n = num.size();
        
//         stack<char> st;
        
//         if(k == 0 || n == 0 ) return num;
        
//         if(k == n) return "0";
        
//         char curr;
//         for(int i = 0; i<n; i++){
//             curr = num[i];
            
//             while(!st.empty() && st.top() > curr && k>0 ){
//                 st.pop();
//                 k--;
//             }
            
//             if(st.size() == 1 && st.top()== '0') st.pop();
            
//             st.push(curr);
//         }
        
//         //edge case , when num is increasing no. like 1234
//         while(k > 0){ // Changed condition to 'while'
//             st.pop();
//             k--;
//         }
        
//         string ans = "";
        
//         while(!st.empty()){
//              ans = st.top() + ans; 
//             st.pop(); 
//         }
        
        
//           while(ans.size() > 1 && ans[0] == '0') // Removed leading zeros
//             ans.erase(0, 1);
        
//         return ans.empty() ? "0" : ans;
        
        
         int n=num.size();
        string ans="";  // works as a stack
        
        for(int i=0;i<n;i++)
        {
            while(ans.length()>0 && ans.back()>num[i] && k>0)
            {
                ans.pop_back();
                k--;
            }
            // to avoid the preeceding zeros
            if(ans.length()>0 || num[i]!='0')
            ans.push_back(num[i]);
        }

        // if num is in increasing order
        while(k>0 && ans.size()>0)
        {
            ans.pop_back();
            k--;
        }

        if(ans== "")
        return "0";
        
        return ans;
    }
};