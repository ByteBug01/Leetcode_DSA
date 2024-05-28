class Solution {
public:
//sliding window-----------------------------------------
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
       
       int currsum = 0;
       int maxlen =0;

       int i  =0; int j = 0;

       while(j<n){
        currsum += abs(s[j] - t[j]);

        while(currsum > maxCost){
            currsum -= abs(s[i] - t[i]);
            i++;
        }

        maxlen = max(maxlen, j - i+1);
        j++;
       }
      return maxlen;
    }
};