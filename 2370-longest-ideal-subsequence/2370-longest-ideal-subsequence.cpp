class Solution {
public:
    
    
    //wrong --------------------//
    // int n = 0;
    // int ans = 0;
    
//     int idealSub(string curr, int k){
        
//         int n = curr.length();
        
//         for(int i = 1; i<n; i++){
//             if(abs(curr[i]-'a' - curr[i-1]-'a') <= k){
//                 continue;
//             }else{
//                 n=0;
//                 break;
//             }
//         }
        
//         return n;
        
//     }
    
    //-----------buteforce not working-------------------//
//     int idealSub(string curr, int k){
//         unordered_set<char> seen;
//         int count = 0;
//         for(int i = 0; i < curr.length(); i++) {
//             if(seen.find(curr[i]) != seen.end()) {
//                 return 0; // Not ideal
//             }
//             seen.insert(curr[i]);
//             count++;
//         }
//         // Check the condition for ideal subsequence
//         for(int i = 1; i < curr.length(); i++) {
//             if(abs(curr[i]-'a' - curr[i-1]-'a') > k) {
//                 return 0; // Not ideal
//             }
//         }
//         return count;
//     }
    
//     void generateSubsequences(string str,int k, string curr = "", int index = 0) {
 
//     if (index == str.length()) {
//         ans = max(ans, idealSub(curr, k));
//         return;
//     }

   
//     generateSubsequences(str, k, curr + str[index], index + 1);

//     generateSubsequences(str, k, curr, index + 1);
// }
    
    //--------------------------------------//

    //approach by LIS DP
//     int longestIdealString(string s, int k) {
        
//     int n = s.length();
        
        
//         vector<int> t(n, 1);// this vector will store atleast 1, bcoz minimum size of subsequence or smallest subsequence is 1
//         int ans = 1;
        
//         for(int i = 0; i<n; i++){
//             for(int j = i-1; j>=0; j--){
//                 if(abs(s[i] - s[j]) <= k){
//                    t[i]= max(t[i], t[j]+1) ;
//                 }
//             }
            
//             ans = max(ans, t[i]);
//         }
        
//         return ans;
//     }
    
    int longestIdealString(string s, int k) {
        
    int n = s.length();
        
        vector<int> t(26, 0);
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int curr = s[i] - 'a';
            
            int left = max(0, curr-k);
            int right = min(25, curr+ k);
            
            int longest = 0;
            
            for(int j = left; j<=right; j++){
                longest =  max(longest, t[j]);
            }
            
            t[curr] = max( t[curr], longest + 1);
            ans = max(ans, t[curr]);
        }
       
        
        return ans;
    }
};