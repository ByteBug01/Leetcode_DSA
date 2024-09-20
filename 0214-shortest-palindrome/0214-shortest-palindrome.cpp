// class Solution {
// public:
// //krooooooooooooooo---
//     string shortestPalindrome(string s) {
//         string rr = s;
//         reverse(rr.begin(), rr.end());
       

//         for(int i = 0; i<s.length(); i++){
//             if(s.substr(0, s.length()-i) == rr.substr(i)){
//                return rr.substr(0, i) + s;
//             }
//         }
//         return rr + s;
//     }
// };

class Solution {
public:

    string shortestPalindrome(string s) {
        int n = s.length();

        if(n == 0) return s; //bhyi ab empty stirng h toh return hi krdo

        int l = 0;

        for(int r = n-1; r>= 0; r--){ //ab jb tk age piche se same h, tb tk dono bdho
            if(s[r] == s[l]){
                l++;
            }
        }

        //if left hi end tk phoch gya toh, palindrome hi h pura string

        if(l == n) return s;

        // agr palindrome ni h, toh bnao

        string suffix = s.substr(l);
        string reverseSuffix = suffix;
         reverse(reverseSuffix.begin(), reverseSuffix.end());

        return reverseSuffix + shortestPalindrome(s.substr(0, l)) + suffix;

    }
};