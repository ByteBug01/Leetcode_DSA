class Solution {
public:
//binary search---------------------------------------------------
    int mySqrt(int x) {
        long long l = 1;
        long long h = x;
        long long ans = 0;
        while(l <= h){
            long long mid = (l+h) / 2;
            long long k = mid * mid;
            if(k <= x){
                ans = mid;
                l = mid+1;
            }else {
                h = mid - 1;
            }
        }

        return ans;
    }
};