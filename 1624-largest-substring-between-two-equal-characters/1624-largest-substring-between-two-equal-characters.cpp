class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
       int n = s.length();
        vector<int> lastOccurrence(26, -1);
        int maxLength = -1;

        for (int i = 0; i < n; ++i) {
            char currentChar = s[i];
            int charIndex = currentChar - 'a';

            if (lastOccurrence[charIndex] != -1) {
                maxLength = max(maxLength, i - lastOccurrence[charIndex] - 1);
            } else {
                lastOccurrence[charIndex] = i;
            }
        }

        return maxLength;
    }
};