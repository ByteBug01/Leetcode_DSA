class Solution {
public:
    long long minimumSteps(string s) {
        int n  = s.length();
        int cnt1 =  0;
        long long steps = 0;
        
        for(int  i = 0; i<n; i++){
            if(s[i] == '1'){
                cnt1++;
            }
            else{
                steps += cnt1;
            }
        }
        
        return steps;
        
//         int n = s.length();
//         int i = 0, j = n-1;
//         long long ans = 0;
        
//         while(i<j){
//             if(s[i] == '1' && s[j] == '0' ){
//                 ans = j - i + 1;
//             }
//             j--;
//             i++;
//         }
//         return ans;
    }
};