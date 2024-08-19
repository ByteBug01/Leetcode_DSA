class Solution {
public:
int solve(int curr, int paste, int n){
    if(curr == n) return 0;

    if(curr > n) return 1000;

    int op1 = 2 + solve(curr*2, curr, n);
    int op2 = 1 + solve(curr+paste, paste, n);

    return min(op1, op2);
}

    int minSteps(int n) {
        if(n == 1) return 0;

        return 1 + solve(1,1,n);
    }
};