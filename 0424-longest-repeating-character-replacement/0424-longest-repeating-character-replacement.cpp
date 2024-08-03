// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//       int n = s.size();
//     int max_length = 0;  // To store the maximum length of substring with same characters
//     int max_count = 0;   // To store the maximum count of any character in the window
//     vector<int> char_count(26, 0);  // To store the count of characters in the window
    
//     int left = 0;  // Left pointer of the sliding window
    
//     for (int right = 0; right < n; ++right) {
//         char_count[s[right] - 'A']++;
//         max_count = max(max_count, char_count[s[right] - 'A']);
        
//         // Calculate the number of characters to change to make all characters in the window the same
//         // This is given by the formula: window size - max count
//         while ((right - left + 1) - max_count > k) {
//             char_count[s[left] - 'A']--;
//             left++;
//         }
        
//         // Update the max_length with the current window size
//         max_length = max(max_length, right - left + 1);
//     }
    
//     return max_length;   
//     }
// };


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int maxcnt = 0;

        int i =0, j=0;

        vector<int>vec(26, 0);

        while(i < n){
            vec[s[i] - 'A']++;
            maxcnt = max(maxcnt, vec[s[i] - 'A']);

            if((i-j+1) - maxcnt > k){
                 vec[s[j] - 'A']--;
                 j++;
            }

            maxlen = max(maxlen, i-j+1);
            i++;
        }

return maxlen;
    }

};