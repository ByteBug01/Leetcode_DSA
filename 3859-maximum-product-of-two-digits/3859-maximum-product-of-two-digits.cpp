class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        sort(s.begin(), s.end());

        int nn = s.size();

        int ans = (s[nn-1] - '0') * (s[nn-2] - '0');

        return ans;

    }
};