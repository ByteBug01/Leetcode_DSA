class Solution {
public:

bool solve(int c){
    if(c < 0) return false;

    long long l = 0;
    long long r = sqrt(c);

    while(l<=r) {
        long long sum = pow(l, 2) + pow(r, 2);

        if(sum == c){
            return true;
        }else if(sum < c){
            l++;
        }else{
            r--;
        }
    }
    return false;
}

    bool judgeSquareSum(int c) {
        
        return solve(c);
    }
};