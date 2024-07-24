class Solution {
public:

 static bool custom(const pair<long long, int>& a, const pair<long long, int>& b) {
        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();

        vector<pair<long long, int>> mp_num(n); 

        for (int i = 0; i < n; ++i) {
            string ori = to_string(nums[i]);
            string ss = "";

            for (char& ch : ori) {
                ss += to_string(mapping[ch - '0']);
            }

            mp_num[i] = {stoll(ss), nums[i]};
        }

        sort(mp_num.begin(), mp_num.end(), custom);

        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            ans.push_back(mp_num[i].second);
        }

        return ans;
    }
};