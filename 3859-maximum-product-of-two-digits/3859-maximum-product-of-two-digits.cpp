class Solution {
public:
    int maxProduct(int n) {
        // string s = to_string(n);

        // sort(s.begin(), s.end());

        // int nn = s.size();

        // int ans = (s[nn-1] - '0') * (s[nn-2] - '0');

        // return ans;


        // without sorting-----------------

        int max1st = INT_MIN;
        int max2nd;

        while(n > 0){
            int tmp = n%10;

            if(tmp > max1st){
                max2nd =  max1st;
                max1st = tmp;
            }else if(tmp > max2nd){
                max2nd = tmp;
            }
            n/=10;
        }
       return max1st * max2nd;
    }
};