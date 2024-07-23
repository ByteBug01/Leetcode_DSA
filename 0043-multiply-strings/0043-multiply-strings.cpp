class Solution {
public:
    string multiply(string num1, string num2) {
         if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.length();
        int n2 = num2.length();
        vector<int> num(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = num[i + j + 1] + mul;
                num[i + j + 1] = sum % 10;
                num[i + j] += sum / 10;
            }
        }

        string ans = "";
        for (int i = 0; i < num.size(); i++) {
            if (!(ans.empty() && num[i] == 0)) {
                ans += to_string(num[i]);
            }
        }

        return ans.empty() ? "0" : ans;
    }
};