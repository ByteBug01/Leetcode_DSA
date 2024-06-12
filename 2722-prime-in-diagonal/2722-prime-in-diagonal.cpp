class Solution {
public:


bool isPrime(int num) {
    if (num <= 1) {
        return false; 
    }
    if (num <= 3) {
        return true; 
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false; 
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false; 
        }
    }
    return true; 
}
    int diagonalPrime(vector<vector<int>>& nums) {
        
        int n = nums[0].size();
       int ans = 0;
        for(int i = 0; i<n; i++){
            if(isPrime(nums[i][i]))
            ans = max(ans, nums[i][i]);

            if(isPrime(nums[i][n-1-i]))
              ans = max(ans,nums[i][n-1-i]);
        }

        return ans;
    }
};