// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       int max=0;
//         int start = 0;
//         int end = 0;
//         set<int> Set;
        
//         while(start<s.size()){
//             auto it = Set.find(s[start]);
            
//             if(it==Set.end()){
//                 if(start-end+1 > max)
//                     max = start-end+1;  // Update the maximum length if a longer substring is found
//                 Set.insert(s[start]);
//                 start++; // Expand the window to the right
//             }else{
//                 Set.erase(s[end]); // Remove the character at the beginning of the window from the set
//                 end++;  // Slide the window to the right
//             }
//         }return max;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

      int n = s.length();
        unordered_map<char, int> mp;

        int left = 0;
        int right = 0;
        int len = 0;

        while (right < n) {
            if (mp.find(s[right]) != mp.end()) {
                left = max(mp[s[right]] + 1, left);
            }

            mp[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};