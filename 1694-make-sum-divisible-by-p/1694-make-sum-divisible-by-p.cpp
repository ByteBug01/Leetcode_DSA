class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long arrsum = 0;
        
        for (auto &it : nums) {
            arrsum = (arrsum + it) % p;
        }

        if (arrsum % p == 0) return 0;

        // for(int i=0; i<n; i++){
        //     long long sum = 0;
        //     long long diff = 0;
        //     for(int j  =i; j<n; j++){
        //         sum += nums[j];
        //         diff = arrsum - sum;
        //         if(diff % p == 0 && diff != 0){
        //             pp.push_back(j-i+1);
        //         }
        //     }
        // }

        // if(pp.empty()) return -1;

        // long long ans = LLONG_MAX;
        // for(int i = 0; i<pp.size(); i++){
        //    ans = min(ans, pp[i]);
        // }

        
        unordered_map<int, int> mp;
        mp[0] = -1;

        long long currsum = 0;
        int minlen = n;

        for (int i = 0; i < n; ++i) {
            currsum = (currsum + nums[i]) % p;

            int remain = (currsum - arrsum + p) % p;

            if (mp.find(remain) != mp.end()) {
                minlen = min(minlen, i - mp[remain]);
            }

            mp[currsum] = i;
        }

        return minlen == n ? -1 : minlen;
    }
};