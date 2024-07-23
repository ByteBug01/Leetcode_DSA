class Solution {
public:
    string minWindow(string s, string t) {
          int n = s.length();
        int rq_cnt = t.length();

        if (n < rq_cnt) return "";

        unordered_map<char, int> mp;
        for (auto& ch : t) {
            mp[ch]++;
        }

        int i = 0, j = 0;
        int minWnd = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];

            if (mp.find(ch) != mp.end()) { //agr map me wo ch ki frq > 0 hai means wnd m wo chiye hme
                mp[ch]--;
                if (mp[ch] >= 0) {
                    rq_cnt--;
                }
            }

            while (rq_cnt == 0) {
                int curr_wnd = j - i + 1;

                if (minWnd > curr_wnd) {
                    minWnd = curr_wnd;
                    start_i = i;
                }

                  // and we try to shrink wnd if possible
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        rq_cnt++;
                    }
                }

                i++;
            }

            j++;
        }

        return (minWnd == INT_MAX) ? "" : s.substr(start_i, minWnd);
    }
};


