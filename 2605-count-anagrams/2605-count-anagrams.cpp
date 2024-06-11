class Solution {
public:
typedef long long ll;
    vector<int> fact;
    int mod = 1e9 + 7;

    // Calculate factorials modulo `mod`
    void factorial(){
        fact[0] = 1;
        for (int i = 1; i <= 1e5; i++) {
            fact[i] = (ll(fact[i-1]) * i) % mod;
        }
    }

    // Function to compute x^y % mod in logarithmic time
    ll modPow(ll x, ll y, int mod) {
        ll res = 1;
        x = x % mod;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % mod;
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
    }

    // Function to find modular inverse of a number under modulo `mod`
    ll modInverse(ll n, int mod) {
        return modPow(n, mod - 2, mod);
    }

    int countAnagrams(string s) {
        fact.resize(1e5 + 1);
        factorial();
        ll ans = 1, cnt = 0;
        unordered_map<char, int> mp;
        s += ' '; // Adding a space to handle the last word properly

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ll val = fact[cnt];
                for (auto it : mp) {
                    val = (val * modInverse(fact[it.second], mod)) % mod;
                }
                ans = (ans * val) % mod;
                cnt = 0;
                mp.clear();
            } else {
                cnt++;
                mp[s[i]]++;
            }
        }

        return ans;
    }
};

//maths //study about modulo inverse