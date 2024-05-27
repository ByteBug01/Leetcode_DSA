class Solution {
public:
// bit manipulation------------------
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
             
        bool sign = true; //positive

        if(divisor < 0 && dividend >= 0) sign = false;
        else if(divisor > 0 && dividend <= 0) sign = false;

        
        long n = abs(dividend);
        long d = abs(divisor);

          long ans = 0;
        while(d<=n){
           int cnt = 0;

           while(n >= d << (cnt+1)) { //d * 2^cnt +1
              cnt++;
           }

           ans += 1 << cnt;
           n -= (d << cnt);
        }

        if( ans == (1<<31) && sign == true )
        return INT_MAX;

        if(ans == (1<<31) && sign == false)
        return INT_MIN;


    return sign ? ans : - ans;
    }
};