class Solution {
public:
    
     int count_0(const string& s0) {
        int cnt0 = 0;
        for (char c : s0) {
            if (c == '0')
                cnt0++;
        }
        return cnt0;
    }
    
    int count_1(const string& s1) {
        int cnt1 = 0;
        for (char c : s1) {
            if (c == '1')
                cnt1++;
        }
        return cnt1;
    }
    
    int maxScore(const string& s) {
        int n = s.length();
        int sum = INT_MIN;
        
        for (int i = 1; i < n; i++) {  // Start from 1 to avoid empty substrings
            string a = s.substr(0, i);
            string b = s.substr(i);
            
            int current_score = count_0(a) + count_1(b);
            sum = max(sum, current_score);
        }
        
        return sum;
    }
};