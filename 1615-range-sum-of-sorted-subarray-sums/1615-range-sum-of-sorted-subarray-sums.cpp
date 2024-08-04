class Solution {
public:
const int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> presum(n+1, 0);

        for(int i =0; i<n; i++){
            presum[i+1] = (presum[i] + nums[i]) % mod;
         }

        priority_queue<int, vector<int>, greater<int>> minheap;

         for(int i = 0 ; i<n; i++){
            for(int j= i+1; j<=n; j++){
                int sum = (presum[j] - presum[i] + mod)% mod;
                minheap.push(sum);
            }
         }

         long long res = 0;

         for(int  i =1; i<=right; i++){
            int curr  = minheap.top();
            minheap.pop();

            if(i >= left){
                res = (res + curr)%mod;
            }
         }

         return res;
    }
};