class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); 

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                int ele = 0;
                int j = i + 1;
                while (cnt <= k) {
                    ele += code[j % n];
                    j++;
                    cnt++;
                }
                result[i] = ele;
            }
        } else if (k < 0) {
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                int ele = 0;
                int j = i - 1;
                while (cnt <= abs(k)) {
                    ele += code[(j + n) % n]; //negative idx handle kro
                    j--;
                    cnt++;
                }
                result[i] = ele;
            }
        } else {
            //already zero initialized
        }

        return result;
    }
};
