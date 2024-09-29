
// class Solution {
// public:
//     bool isvowel(char ch) {
//         return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'u') || (ch == 'o');
//     }

//     int countOfSubstrings(string word, int k) {
//         int n = word.length();
//         int i = 0, j = 0;
//         unordered_map<char, int> vowelcnt;
//         int consocnt = 0;
//         int anscnt = 0;

//         while(i < n) {
   
//             if(isvowel(word[i])) {
//                 vowelcnt[word[i]]++;
//             } else {
//                 consocnt++;
//             }

//             // Shrink window if consonant count exceeds k
//             while(consocnt > k) {
//                 if(isvowel(word[j])) {
//                     vowelcnt[word[j]]--;
//                 } else {
//                     consocnt--;
//                 }
//                 j++;  // Shrink the window from the left
//             }

//             // Check if all vowels are present and consonants == k
//             if(vowelcnt['a'] > 0 && vowelcnt['e'] > 0 && vowelcnt['i'] > 0 &&
//                vowelcnt['o'] > 0 && vowelcnt['u'] > 0 && consocnt == k) {
//                 anscnt++;
//             }

//             i++;
//         }

//         return anscnt;
//     }
// };


class Solution {
public:
int countOfSubstrings(string s, int k) {
     int ans = 0;

    for(int i=0; i<s.size(); i++){

        int a=0, e=0, m=0, o=0,u=0,c=0; 

        for(int j=i;j<s.size();j++){
            if(s[j]=='a') a++;
            else if(s[j]=='e') e++;
            else if(s[j]=='i') m++;
            else if(s[j]=='o') o++;
            else if(s[j]=='u') u++;
            else c++;  

            if(a and e and m and o and u and c==k) ans++;
        }
        
    }
        
    return ans;
}
};
