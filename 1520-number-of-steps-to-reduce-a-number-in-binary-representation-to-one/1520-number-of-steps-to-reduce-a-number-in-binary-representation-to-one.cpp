//  #define ll long long

// class Solution {
// public:
//     int numSteps(string s) {
// //       ll n = s.length();
        
// //         // Convert binary to decimal
// //         ll dec = 0;
// //         for (ll i = n - 1; i >= 0; i--) {
// //             dec += (s[i] - '0') * pow(2, n - 1 - i);
// //         }
        
// //         ll cnt = 0;
        
// //         while (dec != 1) {
// //             if (dec % 2 == 0) {
// //                 dec = dec / 2;
// //             } else {
// //                 dec = dec + 1;
// //             }
// //             cnt++;
// //         }
        
// //         return cnt;
//         ll cnt = 0;
//         while(s!="1"){
//             ll n = s.length();
//             if(s[n-1] == '1'){
//                 int j = n-1;
                
//                 //covert all 1's to 0 until we found the 0 in s
//                 while(j >= 0 && s[j] == '1'){
//                     s[j] = '0';
//                 }
//                 //if all bits of S are 1 then j == -1 then we have to add 1 at first of S
//                 if(j == -1){
//                   s="1"+s;
//                 }
//                 //the addition of 1 if the LSB of s is found to be 0
//                 else{
//                     s[j]='1';
//                 }
//                 cnt++;
//             }
            
//             else{
//                 s.pop_back();
//                 cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };


class Solution {
public:
    void addone(string &s) {
        int i = s.length()-1;

        while(i >= 0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }

        if(i < 0) {
            s = '1' + s;
        } else {
            s[i] = '1';
        }
    }

    int numSteps(string s) {
        int op = 0;

        while(s.length() > 1) {
            int n = s.length();

            if(s[n-1] == '0') {
                s.pop_back();
            } else {
                addone(s);
            }

            op++;
        }

        return op;
    }
};