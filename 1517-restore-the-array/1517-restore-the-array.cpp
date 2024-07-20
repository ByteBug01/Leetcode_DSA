class Solution {
public:
//dp----------------------------

int n ;
const int mod = 1e9 + 7;

long long solve(int start, string & s, int k, vector<int>& t){

    if(start >= n ) return 1;

    if(s[start] == '0') return t[start] =  0;

    long long ans = 0;

    long long num = 0;

    if(t[start] != -1) return t[start];

    for(int end = start; end<n; end++){
        num = (num * 10) + (s[end] - '0');

        if(num > k) break;

        ans = (ans%mod + solve(end+1, s, k, t)% mod)% mod;
    }

    return t[start] = ans;
}


    int numberOfArrays(string s, int k) {
        n =  s.length();

        vector<int> t(n , -1);

        return solve(0, s, k, t);
    }
};