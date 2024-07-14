class Solution {
public:

bool isValidDigit(char c) {
    return c >= '0' && c <= '9';
}

    string getSmallestString(string s) {
        for(int i = 0; i<s.length(); i++){

            if (!isValidDigit(s[i]) || !isValidDigit(s[i + 1])) {
            continue; // Skip non-digit characters
        }
            int a = s[i] - '0';
            int b = s[i+1] - '0';
            if(((a%2 == 0) == (b%2==0) && a>b) || ((a%2 != 0) && (b%2!=0) && a>b) ){
                swap(s[i], s[i+1]);
                break;
            }
        }

        return s;
    }
};