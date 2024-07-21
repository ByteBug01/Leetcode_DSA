class Solution {
public:

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
    bool doesAliceWin(string s) {
        if (s.empty()) return false;

    int vowelCount = 0;
    for (char c : s) {
        if (isVowel(c)) {
            vowelCount++;
        }
    }

    if (vowelCount == 0) return false;

    unordered_map<int, int> vowelParity;
    vowelParity[0] = 1;
    int currentParity = 0;
    int oddCount = 0;

    for (char c : s) {
        if (isVowel(c)) {
            currentParity ^= 1;
        }
        if (currentParity == 1) {
            oddCount++;
        }
        vowelParity[currentParity]++;
    }

    return oddCount > 0;
    }
};